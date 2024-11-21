module game;
import player;
    
char Game::getTile(int x, int y, int player) {return ' ';}
int Game::getLevel() {return 0;}
int Game::getScore() {return 0;}

void Game::run() {
    Player player1 = new Player();
    Player player2 = new Player();
    while (true) {
        player1->runTurn();
        player2->runTurn();
    }
}

