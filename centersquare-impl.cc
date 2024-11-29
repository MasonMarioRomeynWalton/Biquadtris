module centersquare;

import <vector>;
import <utility>;

CenterSquare::CenterSquare(int level, Blocks* component): Decorator{component}, level{level} {}

int CenterSquare::clearRow(int i) {
  int score = 0;
  // check if the square is in the cleared row
  if(coords[0].second == i) {
    // remove the square from the vector of coordinates
    coords.erase(coords.begin()+i);
    // calculate the score of clearing the square
    score += (level+1)*(level+1);
  }
  // cause the square to fall a row if above the cleared row
  if(coords[0].second > i) coords[0].second -= 1;
  // update the score to account for other blocks cleared
  score += component->clearRow(i);
  // check if the next block on the board has been entirely cleared
  if(component->coords.empty()) {
    Blocks* temp = component;
    // remove the next block
    if(dynamic_cast<Decorator*>(component)) {
      component = dynamic_cast<Decorator*>(component)->component;
    }
    else {component = nullptr; }
    delete temp;
  }
  // return the score from cleared blocks on the board
  return score;
}
