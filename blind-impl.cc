module concrete_effects;

Blind::Blind() {
  player->opponent->setBlind(true);
}

Blind::~Blind() {
  player->setBlind(false);
}
