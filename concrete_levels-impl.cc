module concrete_levels;
import level;

import <iostream>;
import <cstdlib>;


Level0::Level0() : Level{false, 0, 0} {}

char Level0::generateBlock() {return '0';}
Level* Level0::nextLevel() {return (new Level1{getSeed()});}
Level* Level0::prevLevel() {return (new Level0{getSeed()});}


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
Level* Level1::nextLevel() {return (new Level2{getSeed()});}
Level* Level1::prevLevel() {return (new Level0{getSeed()});}



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
Level* Level2::nextLevel() {return (new Level2{getSeed()});}
Level* Level2::prevLevel() {return (new Level1{getSeed()});}
