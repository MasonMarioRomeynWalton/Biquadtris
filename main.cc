import game;
import text;
import graphics;

import <string>;
import <iostream>;
import <fstream>;

using namespace std;

string getArg(int argc, char** argv, string arg, string default_value) {
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == arg) {
            return argv[i+1];
        }
    }
    return default_value;
}

int main(int argc, char** argv) {

    // Set the seed of the random number generator for the game
    int seed = stoi(getArg(argc, argv, "-seed", "0"));
    srand(seed);

    // Create the game and set start level and sequence file
    Game* game = new Game{};

    int start_level = stoi(getArg(argc, argv, "-startlevel", "0"));
    ifstream sequenceFile1;
    ifstream sequenceFile2;
    sequenceFile1.open(getArg(argc, argv, "-scriptfile1", "sequence1.txt"));
    sequenceFile2.open(getArg(argc, argv, "-scriptfile2", "sequence2.txt"));

    game->setLevels(start_level, sequenceFile1, sequenceFile2);

    // Attach a text observer to the game
    Text* text = new Text{game, cout};
    game->attach(text);

    // Attach a graphical observer to the game
    Graphics* graphics = new Graphics{game};
    game->attach(graphics);

    // Run the game
    game->run();

    // Free memory
    delete game;
    sequenceFile1.close();
    sequenceFile2.close();

    return 0;
}
