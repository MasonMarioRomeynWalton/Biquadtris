module concrete_levels;
import level;

import <iostream>;
import <fstream>;
import <cstdlib>;

using namespace std;

Level4::Level4(ifstream& inputFile) : Level{1, 4, true, inputFile} {}

GeneratedBlock Level4::generateRandomBlock() {

    GeneratedBlock out {'#', true};
    int block = rand() % 9;

    if (block == 0) {out.block = 'I';}
    else if (block == 1) {out.block = 'J';}
    else if (block == 2) {out.block = 'L';}
    else if (block == 3) {out.block = 'O';}
    else if (block == 4 || block == 5) {out.block = 'S';}
    else if (block == 6 || block == 7) {out.block = 'Z';}
    else if (block == 8) {out.block = 'T';}

    return out;
}

GeneratedBlock Level4::generateFromFile() {
    GeneratedBlock generated_block{'#', true};
    inputFile >> generated_block.block;
    return generated_block;
}

Level* Level4::nextLevel() {return (new Level4{inputFile});}
Level* Level4::prevLevel() {return (new Level3{inputFile});}
