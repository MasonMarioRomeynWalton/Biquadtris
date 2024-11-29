module score;

import <iostream>;
import <vector>;
import <utility>;

Score::Score(): score{0} {}

Score::~Score() {};

// Calculates and returns the new score after all eligible lines are cleared at the end of a turn
int Score::clearLines(int level) {
  std::pair<int,int> scoreData = board.clearAttempt(level);
  score += (scoreData.first + level)*(scoreData.first + level) + scoreData.second;
  return scoreData.first;
}
