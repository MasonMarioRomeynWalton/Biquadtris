module game;
import player;

import <iostream>;
import <fstream>;

using namespace std;
    
char Game::getTile(int row, int col, int player) {
    if (player == 1) {return ((player1.getBoard().getState())[row][col]);}
    if (player == 2) {return ((player2.getBoard().getState())[row][col]);}
    else {return '#';}
}

int Game::getLevel(int player) {
    if (player == 1) {return player1.getLevel()->getNumber();}
    if (player == 2) {return player2.getLevel()->getNumber();}
    else {return -1;}
}
int Game::getScore(int player) {return 0;}
char Game::getNextBlock(int player) {
    if (player == 1) {return player1.getGenBlock();}
    if (player == 2) {return player2.getGenBlock();}
    else {return '#';}
}

void Game::setLevels(int level, ifstream& sequenceFile1, ifstream& sequenceFile2) {
    player1.setLevel(level, sequenceFile1);
    player2.setLevel(level, sequenceFile2);
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

