module game;
import player;
import <iostream>;
using namespace std;
    
char Game::getTile(int x, int y, int player) {return ' ';}
int Game::getLevel() {return 0;}
int Game::getScore() {return 0;}

void Game::run() {
    Player player1 = Player();
    Player player2 = Player();

    player1.setOpponent(&player2);
    player2.setOpponent(&player1);  

    while (true) {
        player1.runTurn();
        if (!cin) {break;}
        player2.runTurn();
        if (!cin) {break;}
    }
}

