module player;
import concrete_levels;

import score;
import board;
import blocks;
import newblock;
import centersquare;

import <string>;
import <iostream>;
import <fstream>;
//import <vector>;
//import <utility>;

using namespace std;

const vector<string> cmdlist = vector<string>{"left","right","down","clockwise","counterclockwise","drop","levelup","leveldown"};

Player::Player() {
    level = nullptr;
}

Player::~Player() {
    delete level;
}

//void Player::attachEffect(Effect* e);
//void Player::clearEffects();
//void Player::drop();

void Player::runTurn() {

    string input;
    // Take input from the user until the turn is over
    while (cin >> input) {
        
        // The number of commands that are matches to the input
        int matches = 0;
        string cmd;

        // Search throught the commands to find matches
        for (auto c : cmdlist) {
            if (input == c.substr(0, input.length())) {
                cmd = c;
                matches++;
            }
        }
        if (matches == 0) {
            cout << "Invalid command" << endl;
            continue;
        } else if (matches > 1) {
            cout << "Ambiguous command" << endl;
            continue;
        } else {

            // Move the piece to the left
            if (cmd == "left") {
                if (!(board.translateAttempt('l'))) {
                    break;
                }
            // Move the piece to the right
            } else if (cmd == "right") {
                if (!(board.translateAttempt('r'))) {
                    break;
                }
            // Move the piece down
            } else if (cmd == "down") {
                if (!(board.translateAttempt('d'))) {
                    break;
                }
            // Rotate the piece clockwise
            } else if (cmd == "clockwise") {
                if (!(board.rotateAttempt('r'))) {
                    break;
                }
            // Rotate the piece counterclockwise
            } else if (cmd == "counterclockwise") {
                if (!(board.rotateAttempt('l'))) {
                    break;
                }
            // Drop the piece to the bottom
            } else if (cmd == "drop") {
                while (board.translateAttempt('d')) {}
                break;
            // Go to the next level
            } else if (cmd == "levelup") {
                Level* temp = level;
                level = level->nextLevel();
                delete temp;
            // Go to the previous level
            } else if (cmd == "leveldown") {
                Level* temp = level;
                level = level->prevLevel();
                delete temp;
            // If the command has not been implemented yet
            } else {
                cout << "This command has no effect" << endl;
                continue;
            }
        }
    }
    // Generate a new block for the next turn
    gen_block = level->generateBlock();

    if(!(board.addNextBlock(gen_block.block, level->getNumber()))) {
    //if(true) {
        //Temporary code to end the game
        cout << "GAME OVER" << endl;
        exit(0);
    }

}

void Player::setLevel(int new_level, ifstream& sequenceFile) {

  // Set the level based on the command line args
  if (new_level == 0) {
    level = new Level0{sequenceFile};
  } else if (new_level == 1) {
    level = new Level1{sequenceFile};
  } else if (new_level == 2) {
    level = new Level2{sequenceFile};
  } else if (new_level == 3) {
    level = new Level3{sequenceFile};
  }

  // Generate the first block of the game
  gen_block = level->generateBlock();
  board.addNextBlock(gen_block.block, level->getNumber());
}
