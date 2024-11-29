export module score;

import board;
import <memory>;

export class Score {
  int score;
  Board board;
 public:
  Score();
  ~Score();
  int clearLines(int level);
  
  Board& getBoard() {return board;}
  int getValue() {return score;}
};
