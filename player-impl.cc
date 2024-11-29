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
  // Add effect to the list of effects so the player knows i's applied
  effects.emplace_back(e);
}
void Player::detachEffect(Effect* e) {
  for(auto it = effects.begin(); it != effects.end();) {
    // Remove the input effect from the list of effects
    if(*it == e) effects.erase(it);
    else ++it;
  }
}
void Player::clearEffects() {
  for(auto e : effects) {
    // Delete all effects to run their destructors
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

bool Player::checkBlock() {
  // return whether the block is in bounds of the board
  return score.getBoard().checkBound(score.getBoard().getBlocks());
}

bool Player::startTurn() {
    // Add the next block
    bool cond = true;
    if (nextBlock.middle) {
        cond = cond && score.getBoard().addNextBlock('*', level->getNumber());
    }
    cond = cond && score.getBoard().addNextBlock(nextBlock.block, level->getNumber());
    nextBlock = level->generateBlock();
    return cond;
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
