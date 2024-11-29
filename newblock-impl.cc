module newblock;

import <utility>;
import <vector>;
import <iostream>;

NewBlock::NewBlock(int level, Blocks* component, std::vector<std::pair<int,int>> coords): Decorator{component}, level{level}, coords{coords} {}

int NewBlock::clearRow(int i) {
  int score = 0;
  for(auto &[x, y] : coords) {
    // Remove the square that was cleared
    if(y == i) coords.erase(coords.begin()+i);
    // drop the square down a row if above the line clear
    if(y > i) y -= 1;
  }
  // if the block was entirely cleared calculate the added score and add the score for clearing other blocks
  if(coords.size() == 0) score += (level+1)*(level+1);
  score += component->clearRow(i);
  // check if the next block should be removed
  if(component->coords.empty()) {
    Blocks* temp = component;
    // remove the next block
    if(dynamic_cast<NewBlock*>(component) != nullptr) {
      component = dynamic_cast<NewBlock*>(component)->component;

      dynamic_cast<NewBlock*>(temp)->component = nullptr;
      delete temp;
    }
  }
  // return teh calculated score
  return score;
}

std::vector<std::pair<int,int>> NewBlock::rotate(char dir) {
  int bottom = 18;
  int left = 12;
  // calculate the position of the bottom left corner of the block
  for(auto &[x, y] : coords) {
    if(x < left) left = x;
    if(y < bottom) bottom = y;
  }
  std::vector<std::pair<int,int>> retVec;
  int x0;
  int y0;
  // calculate the coordinates of each sqaure in the rotated 4x4 grid and standardize it to (0,0)
  for(auto &[x, y] : coords) {
    if(dir == 'r') {
      x0 = y-bottom;
      y0 = 3-(x-left);
    }
    if (dir == 'l') {
      x0 = 3-(y-bottom);
      y0 = x-left;
    }
    // add the square's new position to a new vector
    retVec.emplace_back(std::pair<int,int>{x0,y0});
  }
  x0 = 4;
  y0 = 4;
  // find the bottom left corner of the rotated block
  for(auto &[x, y] : retVec) {
    if(x < x0) x0 = x;
    if(y < y0) y0 = y;
  }
  // destandardize the block back to its initial position
  for(auto &[x, y] : retVec) {
    x = x+left-x0;
    y = y+bottom-y0;
  }
  // return the rotated coordinates
  return retVec;
}

std::vector<std::pair<int,int>> NewBlock::translate(char dir) {
  int h = 0;
  int v = 0;
  // set translation variables
  if(dir == 'l') { h = -1; }
  if(dir == 'r') { h = 1; }
  if(dir == 'd') { v = -1; }
  std::vector<std::pair<int,int>> newCoords;
  // use translation variables to increment the position in the desired direction
  for(auto &[x, y] : coords) {
    newCoords.emplace_back(std::pair<int,int>{x+h,y+v});
  }
  // return the translated coordinates
  return newCoords;
}

// access the block's coordinates
std::vector<std::pair<int,int>> NewBlock::getCoords() { return coords; }
// change the block's coordinates
void NewBlock::setCoords(std::vector<std::pair<int,int>> newCoords) { coords = newCoords; }
