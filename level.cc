export module level;

export class Level {
    bool random;
    int seed;
    int heaviness;
    int number;

    public:
//        virtual char generateBlock(Board& prev);
        Level() = default;
        virtual Level* nextLevel() = 0;
        virtual Level* prevLevel() = 0;
        virtual ~Level() = default;
};
