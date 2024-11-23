import game;
import text;
import <string>;
import <iostream>;

using namespace std;

int main(int argc, char** argv) {
    int seed = 0;

    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-seed") {
            i++;
            if (i < argc) {
                seed = atoi(argv[i]);
            }
        }
    }
    srand(seed);

    Game* game = new Game{};
    Text* text = new Text{game, cout};
    game->attach(text);

    game->run();
    return 0;
}
