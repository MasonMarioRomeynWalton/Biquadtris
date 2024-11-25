export module game;
import subject;
import player;

import <fstream>;

export class Game : public Subject {
        int highScore;
        Player player1;
        Player player2;
    public:
        char getTile(int x, int y, int player);
        int getLevel(int player);
        int getScore(int player);
        char getNextBlock(int player);

        void setLevels(int level, std::ifstream& sequenceFile1, std::ifstream& sequenceFile2);

        void run();
};
