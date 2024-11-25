export module level;
import <iostream>;
import <fstream>;

export struct GeneratedBlock {
    char block;

    // Whether or not there is a 1x1 block added
    bool middle;
};

export class Level {
    int heaviness;
    int number;

    protected:
        bool random;
        std::ifstream& inputFile;

        virtual GeneratedBlock generateFromFile();
        virtual GeneratedBlock generateRandomBlock() = 0;

    public:
        Level() = default;
        Level(int heaviness, int number, bool random, std::ifstream& inputFile);
        virtual ~Level() = default;

        GeneratedBlock generateBlock();

        virtual Level* nextLevel() = 0;
        virtual Level* prevLevel() = 0;

        int getNumber() {return number;}
};

