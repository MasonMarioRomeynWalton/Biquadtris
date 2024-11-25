module blocks;

import <vector>;

Blocks::~Blocks() {}

Decorator::Decorator(Blocks *base): component{base} {}

Decorator::~Decorator() { delete component; }

NoBlocks::NoBlocks() {
  coords = std::vector<std::pair<int,int>>;
}

int NoBlocks::clearRow(int i) {
  return 0;
}
