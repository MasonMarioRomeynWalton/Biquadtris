export module centersquare;

import blocks;
import <vector>;
import <utility>;

export class CenterSquare: public Decorator {
  int level;
 protected:
  std::vector<std::pair<int,int>> coords;
 public:
  CenterSquare(int level, Blocks* component);
  int clearRow(int i);
};
