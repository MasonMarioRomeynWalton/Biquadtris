module centersquare;

import <vector>;
import <utility>;

CenterSquare::CenterSquare(int level, Blocks* component): Decorator{component}, level{level} {}

int CenterSquare::clearRow(int i) {
  int score = 0;
  if(coords[0].second == i) {
    coords.erase(coords.begin()+i);
    score += (level+1)*(level+1);
  }
  if(coords[0].second > i) coords[0].second -= 1;
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
