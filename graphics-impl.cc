module graphics;
import window;

import <string>;

using namespace std;

const int graphics_size = 40;
const int columns = 11;
const int rows = 18;

void Graphics::notify() {


  // Draw the boards
  for (int player = 1; player <= 2; player++) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {

        char colour = whoFrom->getTile(i, j, player);
        char actual_colour;
        if (colour == 'O') {
          actual_colour = window.Yellow;
        } else if (colour == 'I') {
          actual_colour = window.Cyan;
        } else if (colour == 'T') {
          actual_colour = window.Magenta;
        } else if (colour == 'Z') {
          actual_colour = window.Red;
        } else if (colour == 'S') {
          actual_colour = window.Green;
        } else if (colour == 'J') {
          actual_colour = window.Blue;
        } else if (colour == 'L') {
          actual_colour = window.Orange;
        } else if (colour == '?') {
          actual_colour = window.Brown;
        } else if (colour == ' ') {
          actual_colour = window.Black;
        } else {
          actual_colour = window.White;
        }
        if (player == 1) {
            window.fillRectangle((j)*graphics_size, (rows-i-1)*graphics_size, graphics_size, graphics_size, actual_colour);
        } else {
            window.fillRectangle((columns+j+1)*graphics_size, (rows-i-1)*graphics_size, graphics_size, graphics_size, actual_colour);
        }
      }
    }
  }

  // Draw the graphics and the scores
  /*
  for (int player = 1; player <= 2; player++) {
    string score = to_string(whoFrom->getScore(player));
    if (player == 1) {
      window.drawString(graphics_size/2, graphics_size * (rows+1)-graphics_size/2, "Level: " + to_string(whoFrom->getLevel(player)), window.Black);
      window.drawString(graphics_size/2, graphics_size * (rows+1), "Score: " + to_string(whoFrom->getScore(player)), window.Black);
      window.drawString(graphics_size/2, graphics_size * (rows+1)+graphics_size/2, "Next: " + string{whoFrom->getNextBlock(player)}, window.Black);
    } else {
      window.drawString(graphics_size * (columns+1), graphics_size * (rows+1), "Player " + to_string(player) + ": " + score, window.Black);
    }
  }
  */
}





Graphics::Graphics (Game* whoFrom) : whoFrom{whoFrom}, window{Xwindow((columns*2+1)*graphics_size,(rows)*graphics_size)} {
}
