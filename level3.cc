module concrete_levels;
import level;

import <iostream>;
import <fstream>;
import <cstdlib>;

using namespace std;

Level3::Level3(ifstream& inputFile) : Level{1, 3, true, inputFile} {}

GeneratedBlock Level3::generateRandomBlock() {
    int block = rand() % 9;
    GeneratedBlock out {'#', false};

    if (block == 0) {out.block = 'I';}
    else if (block == 1) {out.block = 'J';}
    else if (block == 2) {out.block = 'L';}
    else if (block == 3) {out.block = 'O';}
    else if (block == 4 || block == 5) {out.block = 'S';}
    else if (block == 6 || block == 7) {out.block = 'Z';}
    else if (block == 8) {out.block = 'T';}

    return out;
}

Level* Level3::nextLevel() {return (new Level4{inputFile});}
Level* Level3::prevLevel() {return (new Level2{inputFile});}
