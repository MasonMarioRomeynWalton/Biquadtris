module concrete_levels;
import level;

import <iostream>;
import <cstdlib>;


Level1::Level1() : Level{true, 0, 1} {}

char Level1::generateBlock() {
    int block = rand() % 12;
        if (block == 0 || block == 1) {return 'I';}
        else if (block == 2 || block == 3) {return 'J';}
        else if (block == 4 || block == 5) {return 'L';}
        else if (block == 6 || block == 7) {return 'O';}
        else if (block == 8) {return 'S';}
        else if (block == 9) {return 'Z';}
        else if (block == 10 || block == 11) {return 'T';}
        else {return '1';}
}
Level* Level1::nextLevel() {return (new Level2{});}
Level* Level1::prevLevel() {return (new Level0{});}
