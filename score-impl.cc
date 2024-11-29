module score;

import <iostream>;
import <vector>;
import <utility>;

Score::Score(): score{0} {}

Score::~Score() {};

int Score::clearLines(int level) {
  // get the number of lines and score for clearing entire blocks from the board
  std::pair<int,int> scoreData = board.clearAttempt(level);
  // calculate the score and adds it to the current score
  score += (scoreData.first + level)*(scoreData.first + level) + scoreData.second;
  // return the number of lines cleared
  return scoreData.first;
}
