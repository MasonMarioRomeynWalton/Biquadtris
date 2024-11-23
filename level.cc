export module level;
import <iostream>;
import <fstream>;

export class Level {
    bool random;
    int heaviness;
    int number;

    public:
        Level() = default;
        Level(bool random, int heaviness, int number);
        virtual ~Level() = default;

        char generateFromFile(std::ifstream& f);
        virtual char generateBlock() = 0;
        virtual Level* nextLevel() = 0;
        virtual Level* prevLevel() = 0;

        int getNumber() {return number;}
};
