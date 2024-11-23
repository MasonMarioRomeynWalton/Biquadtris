module concrete_levels;
import level;

import <iostream>;
import <cstdlib>;


Level3::Level3() : Level{true, 1, 3} {}

char Level3::generateBlock() {
    int block = rand() % 9;
        if (block == 0) {return 'I';}
        else if (block == 1) {return 'J';}
        else if (block == 2) {return 'L';}
        else if (block == 3) {return 'O';}
        else if (block == 4 || block == 5) {return 'S';}
        else if (block == 6 || block == 7) {return 'Z';}
        else if (block == 8) {return 'T';}
        else {return '3';}
}
Level* Level3::nextLevel() {return (new Level3{});}
Level* Level3::prevLevel() {return (new Level1{});}
