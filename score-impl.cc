module score;

import <vector>;

Score::Score(int score, Board* board): score{score}, board{board} {}

Score::~Score() {};

int Score::clearAttempt() {
  int lines = 0;
  for(long unsigned int j=0; j < board->getState().size(); ++j) {
    bool full = true;
    for(long unsigned int i=0; i < board->getState()[j].size(); ++i) {
      full = full && (board->getState()[j][i] != ' ');
    }
    if(full) {
      lines += 1;
      board->getState().erase((board->getState()).begin()+j);
      board->getState().emplace_back(std::vector<char>(11, ' '));
    }
  }
  return (level+lines)*(level+lines);
}
