module blocks;

import <vector>;

Blocks::~Blocks() {}

Decorator::Decorator(Blocks *base): component{base} {}

Decorator::~Decorator() { delete component; }

NoBlocks::NoBlocks(std::vector<std::pair<int,int>> coords): coords{coords} {}

int NoBlocks::clearRow(int i) {
  return 0;
}
