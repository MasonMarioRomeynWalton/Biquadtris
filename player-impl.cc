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


Player::Player() : level{nullptr}, is_turn{false} {
}

Player::~Player() {
    delete level;
}

//void Player::attachEffect(Effect* e);
//void Player::clearEffects();

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

void Player::nextLevel() {
    Level* temp = level;
    level = level->nextLevel();
    delete temp;
}

void Player::prevLevel() {
    Level* temp = level;
    level = level->prevLevel();
    delete temp;
}
