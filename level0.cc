module concrete_levels;
import level;

import <iostream>;
import <fstream>;
import <cstdlib>;

using namespace std;

Level0::Level0(ifstream& inputFile) : Level{0, 0, false, inputFile} {}

GeneratedBlock Level0::generateRandomBlock() {
    return generateFromFile();
}
Level* Level0::nextLevel() {return (new Level1{inputFile});}
Level* Level0::prevLevel() {return (new Level0{inputFile});}
