export module level;

import <string>;
import <iostream>;
import <fstream>;

using namespace std;

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
        ifstream& inputFile;

        virtual GeneratedBlock generateFromFile();
        virtual GeneratedBlock generateRandomBlock() = 0;

    public:
        Level() = default;
        Level(int heaviness, int number, bool random, ifstream& inputFile);
        virtual ~Level() = default;

        GeneratedBlock generateBlock();

        virtual Level* nextLevel() = 0;
        virtual Level* prevLevel() = 0;

        void setRandom(bool random) {this->random = random;}
        void setSequenceFile(string inputFile);
        void addWeight(int addedWeight);

        int getNumber() {return number;}
        int getHeaviness() {return heaviness;}
};

