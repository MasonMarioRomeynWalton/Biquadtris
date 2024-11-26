export module newblock;

import blocks;
import <utility>;
import <vector>;

export class NewBlock: public Decorator {
  int level;
 protected:
  std::vector<std::pair<int,int>> coords;
 public:
  NewBlock(int level, Blocks* blocks, std::vector<std::pair<int,int>> coords);
  int clearRow(int i);
  std::vector<std::pair<int,int>> rotate(char dir);
  std::vector<std::pair<int,int>> translate(char dir);
  std::vector<std::pair<int,int>> getCoords();
  void setCoords(std::vector<std::pair<int,int>> newCoords);
};
