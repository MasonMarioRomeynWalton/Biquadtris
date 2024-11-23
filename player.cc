export module player;
import level;
import <vector>;

export class Player {
    private:
        //Board board;
        char board;
        Level* level;
        //std::vector<Effect*> effects;

        int score;
        Player* opponent;
        //bool blind;

        //void addNextBlock();
        //void attachEffect(Effect* e);
        //void clearEffects();
        void nextLevel();
        void prevLevel();
        //bool rotateAttempt(char dir);
        //bool translateAttempt(char dir);
        //void drop();

    public:

        // Constructor
        Player();

        // Run the player's turn
        void runTurn();

        Level* getLevel() {return level;}
        char getBoard() {return board;}

        // Setter for game file
        void setOpponent(Player* p) {opponent = p;}


};
