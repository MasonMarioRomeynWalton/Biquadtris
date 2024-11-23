module level;
import <iostream>;
import <fstream>;

Level::Level(bool random, int heaviness, int number) : random{random}, heaviness{heaviness}, number{number} {}

char generateFromFile(std::ifstream& f) {
    char c;
    f >> c;
    return c;
}
