module level;
import <iostream>;
import <fstream>;

using namespace std;

Level::Level(int heaviness, int number, bool random, ifstream& inputFile) : heaviness{heaviness}, number{number}, random{random}, inputFile{inputFile} {}

char Level::generateBlock() {
    if (random) {
        return generateRandomBlock();
    } else {
        return generateFromFile();
    }
}

char Level::generateFromFile() {
    char c;
    inputFile >> c;
    return c;
}
