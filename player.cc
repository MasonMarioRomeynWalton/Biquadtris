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

        GeneratedBlock gen_block;

        //void attachEffect(Effect* e);
        //void clearEffects();

    public:

        Player();
        ~Player();

        void nextLevel();
        void prevLevel();

        unique_ptr<Level>& getLevel() {return level;}
        char getGenBlock() {return gen_block.block;}
        Board& getBoard() {return board;}

        void setOpponent(Player* p) {opponent = p;}
        void setLevel(int level, std::ifstream& sequencefile);

};
