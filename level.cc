export module level;
import <iostream>;
import <fstream>;

export class Level {
    int heaviness;
    int number;

    protected:
        bool random;
        std::ifstream& inputFile;

        char generateFromFile();
        virtual char generateRandomBlock() = 0;

    public:
        Level() = default;
        Level(int heaviness, int number, bool random, std::ifstream& inputFile);
        virtual ~Level() = default;

        virtual char generateBlock();

        virtual Level* nextLevel() = 0;
        virtual Level* prevLevel() = 0;

        int getNumber() {return number;}
};
