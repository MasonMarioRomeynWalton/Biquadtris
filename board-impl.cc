module board;

import blocks;
import newblock;
import <iostream>;
import <vector>;
import <utility>;

// Initialize the state to the size of the board filled with blank characters and no blocks
Board::Board(): state{std::vector<std::vector<char>>(18, std::vector<char>(11, ' '))}, blocks {new NoBlocks{}} {}

Board::~Board() {}

// Access the state
std::vector<std::vector<char>> Board::getState() { return state; }

std::vector<std::pair<int,int>> Board::getBlocks() {return blocks->getCoords();}

// Get the specified tile that the display should draw
char Board::getTile(int row, int col) {
  // checks if the conditions are met for the tile to be blinded
  if(blind && (col >= 2) && (col <= 8) && (row >= 2) && (row <= 11)) return '?';
  else return state[row][col];
}

bool Board::checkBound(std::vector<std::pair<int,int>> coords) {
  bool ret = true;
  // Check if the specified location is valid for every tile in coords
  for(auto &[x, y] : coords) {
    // Check if the location is in bounds and on a blank tile
    ret = ret && (x >= 0) && (x < 11) && (y >= 0) && (y < 18) && (state[y][x] == ' ');
  }
  return ret;
}

std::pair<int,int> Board::clearAttempt(int level) {
  // Define variables to keep track of returning information
  int lines = 0;
  int blockScore = 0;
  for(long unsigned int j = 0; j < state.size(); ++j) {
    bool full = true;
    // check if every element of the row is not blank
    for(long unsigned int i = 0; i < state[j].size(); ++i) {
      full = full && (state[j][i] != ' ');
    }
    if(full) {
      lines += 1;
      // remove the row and place a new blank on at the end
      state.erase(state.begin() + j);
      state.emplace_back(std::vector<char>(11, ' '));
      // get any update to the score added by clearing an entire block
      blockScore += blocks->clearRow(j);
      j--;
    }
  }
  // return the number of lines cleared and the score achieved by clearing entire blocks
  return std::pair<int,int>{lines, blockScore};
}

bool Board::addNextBlock(char c, int level) {
  // simulate where the next block would be placed
  std::vector<std::pair<int,int>> next;
  switch(c) {
    case 'I':
      next.emplace_back(std::pair<int,int>{0,14});
      next.emplace_back(std::pair<int,int>{1,14});
      next.emplace_back(std::pair<int,int>{2,14});
      next.emplace_back(std::pair<int,int>{3,14});
      break;
    case 'J':
      next.emplace_back(std::pair<int,int>{0,15});
      next.emplace_back(std::pair<int,int>{0,14});
      next.emplace_back(std::pair<int,int>{1,14});
      next.emplace_back(std::pair<int,int>{2,14});
      break;
    case 'L':
      next.emplace_back(std::pair<int,int>{0,14});
      next.emplace_back(std::pair<int,int>{1,14});
      next.emplace_back(std::pair<int,int>{2,14});
      next.emplace_back(std::pair<int,int>{2,15});
      break;
    case 'O':
      next.emplace_back(std::pair<int,int>{0,15});
      next.emplace_back(std::pair<int,int>{0,14});
      next.emplace_back(std::pair<int,int>{1,15});
      next.emplace_back(std::pair<int,int>{1,14});
      break;
    case 'S':
      next.emplace_back(std::pair<int,int>{0,14});
      next.emplace_back(std::pair<int,int>{1,15});
      next.emplace_back(std::pair<int,int>{1,14});
      next.emplace_back(std::pair<int,int>{2,15});
      break;
    case 'Z':
      next.emplace_back(std::pair<int,int>{0,15});
      next.emplace_back(std::pair<int,int>{1,15});
      next.emplace_back(std::pair<int,int>{1,14});
      next.emplace_back(std::pair<int,int>{2,14});
      break;

    case 'T':
      next.emplace_back(std::pair<int,int>{0,15});
      next.emplace_back(std::pair<int,int>{1,15});
      next.emplace_back(std::pair<int,int>{2,15});
      next.emplace_back(std::pair<int,int>{1,14});
      break;
    case '*':
      next.emplace_back(std::pair<int,int>{7,0});
  }
  // check if the next block can be added
  bool cond = checkBound(next);
  if(cond) {
    for(auto &[x, y] : next) {
      // update the state to add the next block
      state[y][x] = c;
    }
    // add the new block to the blocks
    blocks = new NewBlock{level, blocks, next};
  }
  // return whether it was able to add the next block
  return cond;
}

bool Board::rotateAttempt(char dir) {
  // store the initial state of the board
  std::vector<std::vector<char>> oldState (state);
  char b;
  for(auto &[x, y] : blocks->getCoords()) {
    // remove the rotating block from the state
    b = state[y][x];
    state[y][x] = ' ';
  }
  // get the coordinates to the rotated block
  std::vector<std::pair<int,int>> next = blocks->rotate(dir);
  // check if the rotated block can be added to the board with its old position removed
  bool cond = checkBound(next);
  if(cond) {
    for(auto &[x, y] : next) {
      // add the rotated block to the state
      state[y][x] = b;
    }
    blocks->setCoords(next);
  }
  else { 
    // if it can't be rotated, revert the state
    state = oldState; 
  }

  // return whether the rotation was successful
  return cond;
}

// Same function as rotateAttempt, but calls translate on blocks instead of rotate
bool Board::translateAttempt(char dir) {
  std::vector<std::vector<char>> oldState (state);
  char b;
  for(auto &[x, y] : blocks->getCoords()) {
    b = state[y][x];
    state[y][x] = ' ';
  }
  std::vector<std::pair<int,int>> next = blocks->translate(dir);
  bool cond = checkBound(next);
  if(cond) {
    for(auto &[x, y] : next) {
      state[y][x] = b;
    }
    blocks->setCoords(next);
  }
  else {
    state = oldState;
  }

  return cond;
}
