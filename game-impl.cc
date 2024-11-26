module game;
import player;

import <iostream>;
import <fstream>;
import <vector>;

using namespace std;

const vector<string> cmdlist = vector<string>{"left","right","down","clockwise","counterclockwise","drop","levelup","leveldown","norandom","random","seqence","restart","I","O","T","S","Z","J","L"};
    

void Game::run() {
    player1.setOpponent(&player2);
    player2.setOpponent(&player1);  

    Player* current_player = &player1;
    notifyObservers();

    // Main game loop
    while (true) { 
        if (runCommand(cin, true, (current_player))) {
            notifyObservers();
        }
        if (current_player == &player1) {current_player = &player2;}
        else {current_player = &player1;}
    }
}

// Evaluates to whether or not the turn is over
bool Game::runCommand(istream& input, bool draw_board, Player* current_player) {

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
            return false;
        } else if (matches > 1) {
            cout << "Ambiguous command" << endl;
            return false;
        } else {

            // Move the piece to the left
            if (cmd == "left") {
                current_player->getBoard().translateAttempt('l');
                return draw_board;
            // Move the piece to the right
            } else if (cmd == "right") {
                current_player->getBoard().translateAttempt('r');
                return draw_board;
            // Move the piece down
            } else if (cmd == "down") {
               current_player->getBoard().translateAttempt('d');
               return draw_board;
            // Rotate the piece clockwise
            } else if (cmd == "clockwise") {
                current_player->getBoard().rotateAttempt('r');
                return draw_board;
            // Rotate the piece counterclockwise
            } else if (cmd == "counterclockwise") {
                current_player->getBoard().rotateAttempt('l');
                return draw_board;
            // Drop the piece to the bottom
            } else if (cmd == "drop") {
                while (current_player->getBoard().translateAttempt('d')) {}
                return draw_board;
            // Go to the next level
            } else if (cmd == "levelup") {
                current_player->nextLevel();
                return draw_board;
            // Go to the previous level
            } else if (cmd == "leveldown") {
                current_player->prevLevel();
                return draw_board;
            // Set the level to not randomly generate blocks
            } else if (cmd == "norandom") {
                current_player->getLevel()->setRandom(false);
            // Set the level randomly generate blocks
            } else if (cmd == "random") {
                current_player->getLevel()->setRandom(true);
            } else if (cmd == "sequence") {
            // Restart the game
            } else if (cmd == "restart") {
            // Change the falling block
            } else if (cmd == "I") {
            } else if (cmd == "O") {
            } else if (cmd == "T") {
            } else if (cmd == "S") {
            } else if (cmd == "Z") {
            } else if (cmd == "J") {
            } else if (cmd == "L") {
            // If the command has not been implemented yet
            } else {
                cout << "This command has no effect" << endl;
            }
        }
    }
    return false;
}

char Game::getTile(int row, int col, int player) {
    if (player == 1) {return ((player1.getBoard().getState())[row][col]);}
    if (player == 2) {return ((player2.getBoard().getState())[row][col]);}
    else {return '#';}
}

int Game::getLevel(int player) {
    if (player == 1) {return player1.getLevel()->getNumber();}
    if (player == 2) {return player2.getLevel()->getNumber();}
    else {return -1;}
}
int Game::getScore(int player) {return 0;}
char Game::getNextBlock(int player) {
    if (player == 1) {return player1.getGenBlock();}
    if (player == 2) {return player2.getGenBlock();}
    else {return '#';}
}

void Game::setLevels(int level, ifstream& sequenceFile1, ifstream& sequenceFile2) {
    player1.setLevel(level, sequenceFile1);
    player2.setLevel(level, sequenceFile2);
}
