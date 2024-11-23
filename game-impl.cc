module game;
import player;
import <iostream>;
using namespace std;
    
char Game::getTile(int x, int y, int player) {return ' ';}
int Game::getLevel(int player) {
    if (player == 1) {return player1.getLevel()->getNumber();}
    if (player == 2) {return player2.getLevel()->getNumber();}
    else {return -1;}
}
int Game::getScore(int player) {return 0;}
char Game::getNextBlock(int player) {
    if (player == 1) {return player1.getBoard();}
    if (player == 2) {return player2.getBoard();}
    else {return ' ';}
}

void Game::run() {
    player1.setOpponent(&player2);
    player2.setOpponent(&player1);  

    while (true) {
        notifyObservers();
        player1.runTurn();
        if (!cin) {break;}
        notifyObservers();
        player2.runTurn();
        if (!cin) {break;}
    }
}

