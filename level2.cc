module concrete_levels;
import level;

import <iostream>;
import <fstream>;
import <cstdlib>;

using namespace std;

Level2::Level2(ifstream& inputFile) : Level{0, 2, true, inputFile} {}

char Level2::generateRandomBlock() {
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
Level* Level2::nextLevel() {return (new Level3{inputFile});}
Level* Level2::prevLevel() {return (new Level1{inputFile});}
