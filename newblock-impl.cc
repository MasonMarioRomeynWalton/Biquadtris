module newblock;

import <utility>;
import <vector>;

NewBlock::NewBlock(int level, Blocks* component, std::vector<std::pair<int,int>> coords): Decorator{component}, level{level}, coords{coords} {}

int NewBlock::clearRow(int i) {
  int score = 0;
  for(auto &[x, y] : coords) {
    if(y == i) coords.erase(coords.begin()+i);
    if(y > i) y -= 1;
  }
  if(coords.size() == 0) score += (level+1)*(level+1);
  score += component->clearRow(i);
  if(component->coords.empty()) {
    Blocks* temp = component;
    if(dynamic_cast<Decorator*>(component)) {
      component = dynamic_cast<Decorator*>(component)->component;
    }
    else {component = nullptr; }
    delete temp;
  }
  return score;
}

std::vector<std::pair<int,int>> NewBlock::rotate(char dir) {
  int bottom = 18;
  int left = 12;
  for(auto &[x, y] : coords) {
    if(x < left) left = x;
    if(y < bottom) bottom = y;
  }
  std::vector<std::pair<int,int>> retVec;
  int temp;
  int x0;
  int y0;
  for(auto &[x, y] : coords) {
    if(dir == 'r') {
      temp = x;
      x0 = y-bottom;
      y0 = 3-(temp-left);
    }
    else {
      temp = x;
      x0 = 3-(y-bottom);
      y0 = x-left;
    }
    retVec.emplace_back(std::pair<int,int>{x0,y0});
  }
  x0 = 4;
  y0 = 4;
  for(auto &[x, y] : retVec) {
    if(x < x0) x0 = x;
    if(y < y0) y0 = y;
  }
  for(auto &[x, y] : retVec) {
    x = x+left-x0;
    y = y+bottom-y0;
  }
  return retVec;
}

std::vector<std::pair<int,int>> NewBlock::translate(char dir) {
  int h = 0;
  int v = 0;
  if(dir == 'l') { h = -1; }
  if(dir == 'r') { h = 1; }
  if(dir == 'd') { v = -1; }
  std::vector<std::pair<int,int>> newCoords;
  for(auto &[x, y] : coords) {
    newCoords.emplace_back(std::pair<int,int>{x+h,y+v});
  }
  return newCoords;
}

std::vector<std::pair<int,int>> NewBlock::getCoords() { return coords; }
