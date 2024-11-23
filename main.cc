import game;
import <string>;
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
    Game game;
    game.run();
    return 0;
}
