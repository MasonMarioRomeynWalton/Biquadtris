export module player;
import level;
import board;

import <vector>;
import <fstream>;
import <utility>;
import <memory>;

using namespace std;

export class Player {
    private:
        unique_ptr<Level> level;
        Board board;
        //std::vector<Effect*> effects;

        //Score score;
        Player* opponent;

        GeneratedBlock nextBlock;

        //void attachEffect(Effect* e);
        //void clearEffects();

    public:

        Player();
        ~Player();

        //calculateScore();
        void startTurn();

        unique_ptr<Level>& getLevel() {return level;}
        char getNextBlock() {return nextBlock.block;}
        Board& getBoard() {return board;}

        void setOpponent(Player* p) {opponent = p;}
        void setLevel(int level, std::ifstream& sequencefile);
        void setNextBlock(char c) {nextBlock.block = c;}

};
