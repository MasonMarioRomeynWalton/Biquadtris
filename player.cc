export module player;
import level;
import board;

import <vector>;
import <fstream>;

export class Player {
    private:
        Board board;
        GeneratedBlock gen_block;
        Level* level;
        //std::vector<Effect*> effects;

        //Score score;
        Player* opponent;

        bool is_turn;

        //void attachEffect(Effect* e);
        //void clearEffects();

    public:

        // Constructor
        Player();

        // Destructor
        ~Player();


        Level* getLevel() {return level;}
        char getGenBlock() {return gen_block.block;}
        Board getBoard() {return board;}

        // Setter for game file
        void setOpponent(Player* p) {opponent = p;}
        void setLevel(int level, std::ifstream& sequencefile);

        void nextLevel();
        void prevLevel();


};
