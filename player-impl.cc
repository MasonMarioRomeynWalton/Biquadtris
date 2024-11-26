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

//void Player::attachEffect(Effect* e);
//void Player::clearEffects();

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
    board.addNextBlock(nextBlock.block, level->getNumber());
    nextBlock = level->generateBlock();
}
