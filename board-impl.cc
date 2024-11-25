module board;

import blocks;
import newblock;
import <vector>;
import <utility>;

Board::Board() {
  state = std::vector<std::vector<char>>(18, std::vector<char>(11, ' ')); 
  blocks = new NoBlocks{};
}

Board::~Board() {}

std::vector<std::vector<char>> Board::getState() { return state; }

bool Board::checkBound(std::vector<std::pair<int,int>> coords) {
  bool ret = true;
  for(auto &[x, y] : coords) {
    ret = ret && (state[y][x] == ' ');
  }
  return ret;
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
  std::vector<std::pair<int,int>> next = blocks->rotate(dir);
  bool cond = checkBound(next);
  char b;
  if(cond) {
    for(auto &[x, y] : blocks->getCoords()) {
       b = state[y][x];
       state[y][x] = ' ';
    }
    for(auto &[x, y] : next) {
      state[y][x] = b;
    }
  }

  return cond;
}

bool Board::translateAttempt(char dir) {
  std::vector<std::pair<int,int>> next = blocks->translate(dir);
  bool cond = checkBound(next);
  char b;
  if(cond) {
    for(auto &[x, y] : blocks->getCoords()) {
      b = state[y][x];
      state[y][x] = ' ';
    }
    for(auto &[x, y] : next) {
      state[y][x] = b;
    }
  }
  return checkBound(blocks->translate(dir));
}
