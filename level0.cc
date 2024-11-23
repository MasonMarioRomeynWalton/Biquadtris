module concrete_levels;
import level;

import <iostream>;
import <cstdlib>;


Level0::Level0() : Level{false, 0, 0} {}

char Level0::generateBlock() {return '0';}
Level* Level0::nextLevel() {return (new Level1{});}
Level* Level0::prevLevel() {return (new Level0{});}
