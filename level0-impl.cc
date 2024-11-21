module level0;
import level;

//char generateBlock(Board& prev) {}
Level0::Level0() {}
Level0::~Level0() {}


Level* Level0::nextLevel() {return (new Level0{});}
Level* Level0::prevLevel() {return (new Level0{});}
