module level;
import <iostream>;
import <fstream>;
import <string>;

using namespace std;

Level::Level(int heaviness, int number, bool random, ifstream& inputFile) : heaviness{heaviness}, number{number}, random{random}, inputFile{inputFile} {}

GeneratedBlock Level::generateBlock() {
    if (random) {
        return generateRandomBlock();
    } else {
        return generateFromFile();
    }
}

GeneratedBlock Level::generateFromFile() {
    GeneratedBlock generated_block{'#', false};
    inputFile >> generated_block.block;
    return generated_block;
}

void Level::setSequenceFile(string inputFileName) {
    ifstream temp;
    temp.open(inputFileName);
    if (temp) {
        temp.close();
        this->inputFile.close();
        this->inputFile.open(inputFileName);
    } else {
        cerr << "Could not open file " << inputFileName << endl;
    }
}
