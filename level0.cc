export module level0;
import level;

export class Level0 : public Level {

    public:
        //char generateBlock(Board& prev) override;
        Level nextLevel() override;
        Level prevLevel() override;
};
