export module text;
import observer;
import game;
import <iostream>;

export class Text : public Observer{
    Game* whoFrom;
    std::ostream& out;
 public:
    Text(Game* whoFrom, std::ostream& out);
    Text() = default;
    ~Text();
    void notify() override;
};
