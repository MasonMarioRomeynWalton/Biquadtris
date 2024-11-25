module level;
import <iostream>;
import <fstream>;

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
