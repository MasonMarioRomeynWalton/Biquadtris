module graphics;
import window;

using namespace std;

const int columns = 11;
const int rows = 18;

void Graphics::notify() {
  for (int i = rows - 1; i >= 0; --i) {
    for (int j = 0; j < columns; ++j) {

  //for (int i = top; i <= bottom; ++i) {
    //for (int j = left; j <= right; ++j) {
      char colour = whoFrom->getTile(i, j, 1);
      char actual_colour;
      if ((colour >= 'a')&&(colour <= 'z')) {
        actual_colour = window.Red;
      } else if (colour == 'A') {
        actual_colour = window.Green;
      } else if ((colour >= 'G')&&(colour <= '9')) {
        actual_colour = window.Blue;
      } else if (colour == ' ') {
        actual_colour = window.Black;
      } else {
        actual_colour = window.White;
      }
      window.fillRectangle((j)*10, (i)*10, 10, 10, actual_colour);
    }
  }
}



Graphics::Graphics (Game* whoFrom) : whoFrom{whoFrom}, window{Xwindow((columns+1)*10,(rows+1)*10)} {
}
