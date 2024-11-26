export module board;

import blocks;
import <vector>;
import <utility>;

export class Board {
  std::vector<std::vector<char>> state;
  Blocks* blocks;
  bool blind;
  bool checkBound(std::vector<std::pair<int,int>> coords);
 public:
  Board();
  ~Board();
  std::vector<std::vector<char>> getState();
  char getTile(int x, int y);
  bool addNextBlock(char c, int level);
  bool rotateAttempt(char dir);
  bool translateAttempt(char dir);
  std::pair<int,int> clearAttempt(int level);
};
