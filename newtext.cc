#include "text.h"

void Text::notify() {
  out << '+';
  for (int j = left; j <= right; ++j) out << '-';
  out << '+' << std::endl;
  for (int i = top; i <= bottom; ++i) {
    out << '|';
    for (int j = left; j <= right; ++j) {
      out << whoFrom->getState(i, j);
    }
    out << '|' << std::endl;
  }
  out << '+';
  for (int j = left; j <= right; ++j) out << '-';
  out << '+' << std::endl;
}

Text::Text(Studio* whoFrom, int top, int bottom, int left, int right) : whoFrom{whoFrom}, top{top}, bottom{bottom}, left{left}, right{right} {}
