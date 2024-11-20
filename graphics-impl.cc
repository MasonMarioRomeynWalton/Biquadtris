import graphics;

void Graphics::notify() {
  for (int i = top; i <= bottom; ++i) {
    for (int j = left; j <= right; ++j) {
      char colour = whoFrom->getState(i, j);
      char actual_colour;
      if ((colour >= 'a')&&(colour <= 'z')) {
        actual_colour = window.Red;
      } else if ((colour >= 'A')&&(colour <= 'Z')) {
        actual_colour = window.Green;
      } else if ((colour >= '0')&&(colour <= '9')) {
        actual_colour = window.Blue;
      } else if (colour == ' ') {
        actual_colour = window.White;
      } else {
        actual_colour = window.Black;
      }
      window.fillRectangle((j-left)*10, (i-top)*10, 10, 10, actual_colour);
    }
  }
}



Graphics::Graphics (Studio* whoFrom, int top, int bottom, int left, int right) : whoFrom{whoFrom}, top{top}, bottom{bottom}, left{left}, right{right}, window{Xwindow((right-left+1)*10,(bottom-top+1)*10)} {
}
