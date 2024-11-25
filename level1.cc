module concrete_levels;
import level;

import <iostream>;
import <fstream>;
import <cstdlib>;

using namespace std;

Level1::Level1(ifstream& inputFile) : Level{0, 1, true, inputFile} {}

char Level1::generateRandomBlock() {
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
Level* Level1::nextLevel() {return (new Level2{inputFile});}
Level* Level1::prevLevel() {return (new Level0{inputFile});}
