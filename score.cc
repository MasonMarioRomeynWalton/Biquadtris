export module score;

import board;

export class Score {
  int score;
  Board* board;
 public:
  Score(int score, Board* board);
  ~Score();
  int clearLines(int level);
};
