export module game;
import subject;
import player;

export class Game : public Subject {
        int highScore;
        Player player1;
        Player player2;
    public:
        char getTile(int x, int y, int player);
        int getLevel(int player);
        int getScore(int player);
        char getNextBlock(int player);
        void run();
};
