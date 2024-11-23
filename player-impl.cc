module player;
import concrete_levels;

import <string>;
import <iostream>;
using namespace std;

const vector<string> cmdlist = vector<string>{"left","right","down","clockwise","counterclockwise","drop","levelup","leveldown"};

Player::Player() {
    //board = vector<vector<char> >(20, vector<char>(10, ' '));
    level = new Level0{};
}

//void Player::addNextBlock();
//void Player::attachEffect(Effect* e);
//void Player::clearEffects();
void Player::nextLevel() {}
void Player::prevLevel() {}
//bool Player::rotateAttempt(char dir);
//bool Player::translateAttempt(char dir);
//void Player::drop();
void Player::runTurn() {

    board = level->generateBlock();
    //cout << "Your piece is:" << piece << endl;

    string input;
    // Take input from the user until the turn is over
    while (cin >> input) {
        
        // Take input from the user
        //cin >> input;

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
                cout << "left" << endl;
            // Move the piece to the right
            } else if (cmd == "right") {
                cout << "right" << endl;
            // Move the piece down
            } else if (cmd == "down") {
                cout << "down" << endl;
            // Rotate the piece clockwise
            } else if (cmd == "clockwise") {
                cout << "clockwise" << endl;
            // Rotate the piece counterclockwise
            } else if (cmd == "counterclockwise") {
                cout << "counterclockwise" << endl;
            // Drop the piece to the bottom
            } else if (cmd == "drop") {
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
}

//void Player::setOpponent(Player* p) {opponent = p;}
