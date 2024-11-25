module concrete_levels;
import level;

import <iostream>;
import <fstream>;
import <cstdlib>;

using namespace std;

Level2::Level2(ifstream& inputFile) : Level{0, 2, true, inputFile} {}

GeneratedBlock Level2::generateRandomBlock() {
    int block = rand() % 7;
    GeneratedBlock out {'#', false};

    if (block == 0) {out.block = 'I';}
    else if (block == 1) {out.block = 'J';}
    else if (block == 2) {out.block = 'L';}
    else if (block == 3) {out.block = 'O';}
    else if (block == 4) {out.block = 'S';}
    else if (block == 5) {out.block = 'Z';}
    else if (block == 6) {out.block = 'T';}

    return out;
}
Level* Level2::nextLevel() {return (new Level3{inputFile});}
Level* Level2::prevLevel() {return (new Level1{inputFile});}
