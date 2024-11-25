export module board;

import blocks;
import <vector>;
import <utility>;

export class Board {
  std::vector<std::vector<char>> state;
  Blocks* blocks;
  bool checkBound(std::vector<std::pair<int,int>> coords);
 public:
  Board(std::vector<std::vector<char>> state, Blocks* blocks);
  ~Board();
  std::vector<std::vector<char>> getState();
  bool addNextBlock(char c);
  bool rotateAttempt(char dir);
  bool translateAttempt(char dir);
};
