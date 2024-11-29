export module game;
import subject;
import player;

import <fstream>;
import <string>;
import <iostream>;
import <memory>;

using namespace std;

export class Game : public Subject {
        unique_ptr<ifstream> inputFile;

        int highScore;
        Player player1;
        Player player2;
    public:

        Game();
        ~Game();

        void run();
        bool runCommand(bool print, Player* current_player);
        string getInput(istream& input);
        

        char getTile(int x, int y, int player);
        int getLevel(int player);
        int getScore(int player);
        char getNextBlock(int player);

        void setLevels(int level, std::ifstream& sequenceFile1, std::ifstream& sequenceFile2);

};
