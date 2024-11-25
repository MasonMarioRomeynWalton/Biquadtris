export module player;
import level;
import <vector>;
import <fstream>;

export class Player {
    private:
        //Board board;
        GeneratedBlock gen_block;
        Level* level;
        //std::vector<Effect*> effects;

        //int score;
        Player* opponent;
        //bool blind;

        //void attachEffect(Effect* e);
        //void clearEffects();
        void nextLevel();
        void prevLevel();
        //void drop();

    public:

        // Constructor
        Player();

        // Destructor
        ~Player();

        // Run the player's turn
        void runTurn();

        Level* getLevel() {return level;}
        char getBoard() {return gen_block.block;}

        // Setter for game file
        void setOpponent(Player* p) {opponent = p;}
        void setLevel(int level, std::ifstream& sequencefile);


};
