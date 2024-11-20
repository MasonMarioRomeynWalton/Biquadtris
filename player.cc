import vector;

export class Player {
    private:
        Board board;
        Level level;
        vector<Effect*> effects;

        int score;
        int seed;
        Player *opponent;
        vector<vector<char>> board;
        bool blind;

        void addNextBlock();
        void attachEffect(Effect* e);
        void clearEffects();
        void nextLevel();
        void prevLevel();
        bool rotateAttempt(char dir);
        bool translateAttempt(char dir);
        void drop();

    public:
        void runTurn();
};
