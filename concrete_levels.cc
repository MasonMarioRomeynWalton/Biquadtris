export module concrete_levels;
import level;

export class Level0 : public Level {
    public:
        Level0();
        char generateBlock() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};

export class Level1 : public Level {
    public:
        Level1();
        char generateBlock() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};

export class Level2 : public Level {
    public:
        Level2();
        char generateBlock() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};

export class Level3 : public Level {
    public:
        Level3();
        char generateBlock() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};
