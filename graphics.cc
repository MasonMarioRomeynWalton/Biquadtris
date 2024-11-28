#include <window.h>
export module graphics;
import observer;
import studio;

export class Graphics : public Observer{
 private:
  Studio* whoFrom;
  int top;
  int bottom;
  int left;
  int right;
  Xwindow window;
 public:
  void notify();
};
