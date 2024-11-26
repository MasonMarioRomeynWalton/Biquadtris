module blocks;

import <vector>;

Blocks::~Blocks() {}

Decorator::Decorator(Blocks *base): component{base} {}

Decorator::~Decorator() { delete component; }

NoBlocks::NoBlocks() {
  coords = std::vector<std::pair<int,int>>{};
}

std::vector<std::pair<int,int>> NoBlocks::rotate(char dir) { return coords; }
std::vector<std::pair<int,int>> NoBlocks::translate(char dir) { return coords; }

int NoBlocks::clearRow(int i) {
  return 0;
}

std::vector<std::pair<int,int>> NoBlocks::getCoords() { return coords; }
void NoBlocks::setCoords(std::vector<std::pair<int,int>> newCoords) { coords = newCoords; }
