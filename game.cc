export module game;
import subject;

export class Game : public Subject {
        int highScore;
        int seed;
    public:
        char getTile(int x, int y, int player);
        int getLevel();
        int getScore();
        void run();
};
