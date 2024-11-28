module concrete_effects;

Blind::Blind(Player* player): player{player} {
  player->getOpponent()->getBoard().setBlind(true);
}

Blind::~Blind() {
  player->getBoard().setBlind(false);
}
