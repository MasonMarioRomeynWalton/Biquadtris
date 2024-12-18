module game;
import player;
import level;
import effects;
import concrete_effects;

import <iostream>;
import <fstream>;
import <vector>;
import <memory>;

using namespace std;

const vector<string> cmdlist = vector<string>{"left","right","down","clockwise","counterclockwise","drop","levelup","leveldown","norandom","random","sequence","restart","I","O","T","S","Z","J","L"};
    
Game::Game() : inputFile{nullptr}, highScore{0} {}
Game::~Game() {}

void Game::run() {
    player1.setOpponent(&player2);
    player2.setOpponent(&player1);  

    Player* current_player = &player1;
    
    string effect;

    // Main game loop
    while (true) { 
        // check if the next block can be placed
        if(!current_player->startTurn()) {
          cout<<"GAME OVER. Player: "<<((current_player == &player1) ? 2 : 1)<<" wins!"<<endl;
        };
        notifyObservers();

        while (!(runCommand(true, (current_player)))) {}
        if(current_player->checkBlock()) {
          cout<<"GAME OVER. Player: "<<((current_player == &player1) ? 2 : 1)<<" wins!"<<endl;
        }

        // end turn, test if effect should be added
        current_player->clearEffects();
        effect = current_player->endTurn();
        if (effect != "") {
          // identify and have player apply the effect
          if(effect == "blind") {
              new Blind(current_player->getOpponent());
          } else if(effect == "heavy") {
              new Heavy(current_player->getOpponent());
          } else if(effect == "force") {
              char forced;
              while(!((forced == 'I') || (forced == 'O') || (forced == 'T') || (forced == 'S') || (forced == 'Z') || (forced == 'J') || (forced == 'L'))) {
                cin>>forced;
              }
              new Force(forced, current_player->getOpponent());
          }
        }
        // update high score
        if(current_player->getScore() > highScore) {
            highScore = current_player->getScore();
        }
        // call game over if the input file has been exhausted
        if (cin.eof()) {
            cout << "Game over!" << endl;
            return;
        }

        // Change the current player
        current_player = current_player->getOpponent();
    }
}

// Evaluates to whether or not the turn is over
bool Game::runCommand(bool draw_board, Player* current_player) {

    string cmd;

    // If the no more input is available
    if (cin.eof()) {return true;}
    // If the input file is over
    if (inputFile != nullptr && !(inputFile->eof())) {
        cmd = getInput(*inputFile);
        if (inputFile->eof()) {
            notifyObservers();
            draw_board = true;
        } else {
            draw_board = false;
        }
    } else {
        cmd = getInput(cin);
    };
    // If the command is invalid
    if (cmd == "") {return false;}

    bool success;

    // Move the piece to the left
    if (cmd == "left") {
        success = current_player->getBoard().translateAttempt('l');
        int i = 0;
        while (success && i < current_player->getLevel()->getHeaviness()) {
            if (!(current_player->getBoard().translateAttempt('d'))) {
                if (draw_board) {notifyObservers();}
                return true;
            }
            i++;
        }
        if (success && draw_board) {notifyObservers();}
        return false;
    // Move the piece to the right
    } else if (cmd == "right") {
        success = current_player->getBoard().translateAttempt('r');
        int i = 0;
        while (success && i < current_player->getLevel()->getHeaviness()) {
            if (!(current_player->getBoard().translateAttempt('d'))) {
                if (draw_board) {notifyObservers();}
                return true;
            }
            i++;
        }
        if (success && draw_board) {notifyObservers();}
        return false;
    // Move the piece down
    } else if (cmd == "down") {
        success = current_player->getBoard().translateAttempt('d');
        int i = 0;
        while (success && i < current_player->getLevel()->getHeaviness()) {
            if (!(current_player->getBoard().translateAttempt('d'))) {
                if (draw_board) {notifyObservers();}
                return true;
            }
            i++;
        }
        if (success && draw_board) {notifyObservers();}
        return !success;
    // Rotate the piece clockwise
    } else if (cmd == "clockwise") {
        success = current_player->getBoard().rotateAttempt('r');
        int i = 0;
        while (success && i < current_player->getLevel()->getHeaviness()) {
            if (!(current_player->getBoard().translateAttempt('d'))) {
                if (draw_board) {notifyObservers();}
                return true;
            }
            i++;
        }
        if (success && draw_board) {notifyObservers();}
        return false;
    // Rotate the piece counterclockwise
    } else if (cmd == "counterclockwise") {
        success = current_player->getBoard().rotateAttempt('l');
        int i = 0;
        while (success && i < current_player->getLevel()->getHeaviness()) {
            if (!(current_player->getBoard().translateAttempt('d'))) {
                if (draw_board) {notifyObservers();}
                return true;
            }
            i++;
        }
        if (success && draw_board) {notifyObservers();}
        return false;
    // Drop the piece to the bottom
    } else if (cmd == "drop") {
        while (current_player->getBoard().translateAttempt('d')) {}
        return true;
    // Go to the next level
    } else if (cmd == "levelup") {
        current_player->getLevel() = unique_ptr<Level> (current_player->getLevel()->nextLevel());
        if (draw_board) {notifyObservers();}
        return false;
    // Go to the previous level
    } else if (cmd == "leveldown") {
        current_player->getLevel() = unique_ptr<Level> (current_player->getLevel()->prevLevel());
        if (draw_board) {notifyObservers();}
        return false;
    // Set the level to not randomly generate blocks
    } else if (cmd == "norandom") {
        current_player->getLevel()->setRandom(false);
        string s;

        if (inputFile != nullptr && !(inputFile->eof())) {
            *inputFile >> s;
        } else {
            cin >> s;
        }

        current_player->getLevel()->setSequenceFile(s);
        return false;
    // Set the level randomly generate blocks
    } else if (cmd == "random") {
        current_player->getLevel()->setRandom(true);
        return false;
    // Input a sequence of commands
    } else if (cmd == "sequence") {
        string fileName;

        if (inputFile != nullptr && !(inputFile->eof())) {
            *inputFile >> fileName;
        } else {
            cin >> fileName;
        }

        inputFile = unique_ptr<ifstream> (new ifstream{fileName});
        if (!inputFile->is_open()) {
            cout << "Unable to open file" << endl;
            inputFile = nullptr;
        }
        return false;
    // Restart the game
    } else if (cmd == "restart") {
        return false;
    // Change the falling block
    } else if (cmd == "I") {
        current_player->setNextBlock('I');
        return false;
    } else if (cmd == "O") {
        current_player->setNextBlock('O');
        return false;
    } else if (cmd == "T") {
        current_player->setNextBlock('T');
        return false;
    } else if (cmd == "S") {
        current_player->setNextBlock('S');
        return false;
    } else if (cmd == "Z") {
        current_player->setNextBlock('Z');
        return false;
    } else if (cmd == "J") {
        current_player->setNextBlock('J');
        return false;
    } else if (cmd == "L") {
        current_player->setNextBlock('L');
        return false;
    // If the command has not been implemented yet
    } else {
        cout << "This command has no effect" << endl;
        return false;
    }
}

string Game::getInput(istream& input) {
    // Get the user's input
    string userInput;

    // Take input from the user 
    if (input >> userInput) {
        
        // The number of commands that are matches to the input
        int matches = 0;
        string cmd;

        // Search throught the commands to find matches
        for (auto c : cmdlist) {
            if (userInput == c.substr(0, userInput.length())) {
                cmd = c;
                matches++;
            }
        }
        if (matches == 0) {
            cout << "Invalid command" << endl;
            return "";
        } else if (matches > 1) {
            cout << "Ambiguous command" << endl;
            return "";
        } else {
            return cmd;
        }

    } else {
        return "";
    }
}

char Game::getTile(int row, int col, int player) {
    if (player == 1) {return player1.getBoard().getTile(row, col);}
    if (player == 2) {return player2.getBoard().getTile(row, col);}
    else {return '#';}
}

int Game::getLevel(int player) {
    if (player == 1) {return player1.getLevel()->getNumber();}
    if (player == 2) {return player2.getLevel()->getNumber();}
    else {return -1;}
}
int Game::getScore(int player) {
  if(player == 1) return player1.getScore();
  if(player == 2) return player2.getScore();
  else return -1;
}
char Game::getNextBlock(int player) {
    if (player == 1) {return player1.getNextBlock();}
    if (player == 2) {return player2.getNextBlock();}
    else {return '#';}
}

void Game::setLevels(int level, ifstream& sequenceFile1, ifstream& sequenceFile2) {
    player1.setLevel(level, sequenceFile1);
    player2.setLevel(level, sequenceFile2);
}
