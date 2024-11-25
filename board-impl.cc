module board;

import <vector>;
import <utility>;

Board::Board() {
  state = std::vector<std::vector<char>>; 
  blocks = new NewBlock{};
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

bool Board::addNextBlock(char c) {
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
 return checkBound(next);
}

bool Board::rotateAttempt(char dir) {
  return checkBound(blocks->rotate(dir));
}

bool Board::translateAttempt(char dir) {
  return checkBound(blocks->translate(dir));
}
