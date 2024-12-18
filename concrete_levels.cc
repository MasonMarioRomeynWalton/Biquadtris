export module concrete_levels;
import level;

import <fstream>;

export class Level0 : public Level {
    public:
        Level0(std::ifstream& inputFile);
        GeneratedBlock generateRandomBlock() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};

export class Level1 : public Level {
    public:
        Level1(std::ifstream& inputFile);
        GeneratedBlock generateRandomBlock() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};

export class Level2 : public Level {
    public:
        Level2(std::ifstream& inputFile);
        GeneratedBlock generateRandomBlock() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};

export class Level3 : public Level {
    public:
        Level3(std::ifstream& inputFile);
        GeneratedBlock generateRandomBlock() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};

export class Level4 : public Level {
    private:
        int count;
    public:
        Level4(std::ifstream& inputFile);
        GeneratedBlock generateRandomBlock() override;
        GeneratedBlock generateFromFile() override;
        Level* prevLevel() override;
        Level* nextLevel() override;
};
