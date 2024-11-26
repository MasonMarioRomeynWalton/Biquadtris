module board;

import blocks;
import newblock;
import <iostream>;
import <vector>;
import <utility>;

Board::Board() {
  state = std::vector<std::vector<char>>(18, std::vector<char>(11, ' ')); 
  blocks = new NoBlocks{};
}

Board::~Board() {}

std::vector<std::vector<char>> Board::getState() { return state; }

char Board::getTile(int x, int y) {
  if(!blind) return state[y][x];
  else return '?';
}

bool Board::checkBound(std::vector<std::pair<int,int>> coords) {
  bool ret = true;
  for(auto &[x, y] : coords) {
    ret = ret && (x >= 0) && (x < 11) && (y >= 0) && (y < 18) && (state[y][x] == ' ');
  }
  return ret;
}

std::pair<int,int> Board::clearAttempt(int level) {
  int lines = 0;
  int blockScore = 0;
  for(long unsigned int j = 0; j < state.size(); ++j) {
    bool full = true;
    for(long unsigned int i = 0; i < state[j].size(); ++i) {
      full = full && (state[j][i] != ' ');
    }
    if(full) {
      lines += 1;
      state.erase(state.begin() + j);
      state.emplace_back(std::vector<char>(11, ' '));
      blockScore += blocks->clearRow(j);
    }
  }
  return std::pair<int,int>{lines, blockScore};
}

bool Board::addNextBlock(char c, int level) {
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
  }
  bool cond = checkBound(next);
  if(cond) {
    for(auto &[x, y] : next) {
      state[y][x] = c;
    }
    blocks = new NewBlock{level, blocks, next};
  }
  return cond;
}

bool Board::rotateAttempt(char dir) {
  std::vector<std::vector<char>> oldState (state);
  char b;
  for(auto &[x, y] : blocks->getCoords()) {
    b = state[y][x];
    state[y][x] = ' ';
  }
  std::vector<std::pair<int,int>> next = blocks->rotate(dir);
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
