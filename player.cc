export module player;
import level;
import board;
import score;
import effects;

import <vector>;
import <fstream>;
import <utility>;
import <memory>;
import <string>;

using namespace std;

export class Player {
    private:
        unique_ptr<Level> level;
        std::vector<Effect*> effects;

        Score score;
        Player* opponent;

        GeneratedBlock nextBlock;

    public:

        Player();
        ~Player();

        bool startTurn();
        string endTurn();

        void attachEffect(Effect* e);
        void detachEffect(Effect* e);
        void clearEffects();

        bool checkBlock();

        unique_ptr<Level>& getLevel() {return level;}
        char getNextBlock() {return nextBlock.block;}
        Board& getBoard() {return score.getBoard();}
        Player* getOpponent() {return opponent;}
        int getScore() {return score.getValue();}

        void setOpponent(Player* p) {opponent = p;}
        void setLevel(int level, std::ifstream& sequencefile);
        void setNextBlock(char c) {nextBlock.block = c;}

};
