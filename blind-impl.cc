module concrete_effects;

import player;
import effects;

// Constructor
Blind::Blind(Player* player): player{player} {
  // indicate to a player's board that it is blinded
  player->getBoard().setBlind(true);
  // indicate to a player that it has an effect
  player->attachEffect(this);
}

// Desctructor
Blind::~Blind() {
  // indicate to the player that the effect is no longer applied
  player->getBoard().setBlind(false);
  player->detachEffect(this);
}
