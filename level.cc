export module level;

export class Level {
    bool random;
    int seed;
    int heaviness;
    int number;

    public:
//        virtual char generateBlock(Board& prev);
        Level() = default;
        virtual Level nextLevel();
        virtual Level prevLevel();
        virtual ~Level();
};
