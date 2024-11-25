export module score;

import board;

export class Score {
  int score;
  int level;
  Board* board;
 public:
  Score(int score, Board* board);
  ~Score();
  int clearAttempt();
};
