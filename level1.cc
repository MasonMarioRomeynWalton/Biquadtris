module concrete_levels;
import level;

import <iostream>;
import <fstream>;
import <cstdlib>;

using namespace std;

Level1::Level1(ifstream& inputFile) : Level{0, 1, true, inputFile} {}

GeneratedBlock Level1::generateRandomBlock() {
    int block = rand() % 12;
    GeneratedBlock out {'#', false};

    if (block == 0 || block == 1) {out.block = 'I';}
    else if (block == 2 || block == 3) {out.block = 'J';}
    else if (block == 4 || block == 5) {out.block = 'L';}
    else if (block == 6 || block == 7) {out.block = 'O';}
    else if (block == 8) {out.block = 'S';}
    else if (block == 9) {out.block = 'Z';}
    else if (block == 10 || block == 11) {out.block = 'T';}

    return{out};
}
Level* Level1::nextLevel() {return (new Level2{inputFile});}
Level* Level1::prevLevel() {return (new Level0{inputFile});}
