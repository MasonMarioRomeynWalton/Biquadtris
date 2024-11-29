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
import <memory>;

using namespace std;


Player::Player() : level{nullptr} {}
Player::~Player() {}

void Player::attachEffect(Effect* e) {
  effects.emplace_back(e);
}
void Player::detachEffect(Effect* e) {
  for(auto it = effects.begin(); it != effects.end();) {
    if(*it == e) effects.erase(it);
    else ++it;
  }
}
void Player::clearEffects() {
  for(auto e : effects) {
    delete e;
  }
}

void Player::setLevel(int new_level, ifstream& sequenceFile) {

  // Set the level based on the command line args
  if (new_level == 0) {
      level = unique_ptr<Level> (new Level0{sequenceFile});
  } else if (new_level == 1) {
      level = unique_ptr<Level> (new Level1{sequenceFile});
  } else if (new_level == 2) {
      level = unique_ptr<Level> (new Level2{sequenceFile});
  } else if (new_level == 3) {
      level = unique_ptr<Level> (new Level3{sequenceFile});
  }

  // Generate the first block of the game
  nextBlock = level->generateBlock();
}

void Player::startTurn() {
    // Add the next block
    score.getBoard().addNextBlock(nextBlock.block, level->getNumber());
    nextBlock = level->generateBlock();
}

string Player::endTurn() {
  // Attempt to clear lines
  if(score.clearLines(level->getNumber()) >= 2) {
    // Add an effect if more than 1 line is cleared
    while(true) {
      cout<<"Choose a Special Action"<<endl;
      string action;
      cin >> action;
      if((action == "blind") || 
         (action == "heavy") ||
         (action == "force")) {
        return action;
      }
    }
  }
  else return "";
}
