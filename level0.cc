export module level0;
import level;

export class Level0 : public Level {

    public:
        Level0();
        //Level0() = default;
        //char generateBlock(Board& prev) override;
        Level* prevLevel() override;
        Level* nextLevel() override;
        //Level* prevLevel();
        //Level* nextLevel();
        ~Level0();
};
