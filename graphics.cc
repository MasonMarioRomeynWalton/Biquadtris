export module graphics;

import window;

import observer;
import game;

//#include "window.cc"

export class Graphics : public Observer{
 private:
  Game* whoFrom;
  Xwindow window;
 public:
  Graphics(Game* whoFrom);
  void notify();
};
