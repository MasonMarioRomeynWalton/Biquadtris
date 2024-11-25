module text;
import <iostream>;

using namespace std;

const int columns = 11;
const int rows = 18;

Text::Text(Game* whoFrom, ostream& out) : whoFrom{whoFrom}, out{out} {}

void Text::notify() {
    for (int player = 1; player <= 2; player++) {
        out << "Level: " << '\t' << whoFrom->getLevel(player) << endl;
        out << "Score: " << '\t' << whoFrom->getScore(player) << endl;
        for (int i = 0; i < columns; ++i) {
            out << '-';
        }
        out << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                out << whoFrom->getTile(i, j, player);        
            }
            out << endl;
        }
        for (int i = 0; i < columns; ++i) {
            out << '-';
        }
        out << endl;
        out << "Next: " << '\t' << whoFrom->getNextBlock(player) << endl;

        cout << '\n' << endl;
    }
}

