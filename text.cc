export module text;
import observer;
import game;
import <iostream>;

export class Text : public Observer{
    Game* subject;
    std::ostream out;
 public:
  void notify();
};
