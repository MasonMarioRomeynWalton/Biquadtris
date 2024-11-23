module concrete_levels;
import level;

import <iostream>;
import <cstdlib>;


Level2::Level2() : Level{true, 0, 2} {}

char Level2::generateBlock() {
    int block = rand() % 7;
        if (block == 0) {return 'I';}
        else if (block == 1) {return 'J';}
        else if (block == 2) {return 'L';}
        else if (block == 3) {return 'O';}
        else if (block == 4) {return 'S';}
        else if (block == 5) {return 'Z';}
        else if (block == 6) {return 'T';}
        else {return '2';}
}
Level* Level2::nextLevel() {return (new Level3{});}
Level* Level2::prevLevel() {return (new Level1{});}
