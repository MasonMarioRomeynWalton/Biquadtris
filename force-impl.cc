module concrete_effects;

import player;
import effects;

// Constructor
Force::Force(char forcedBlock, Player* player): Effect{}, player{player} {
  // changes the player's next block to the forced block
  player->setNextBlock(forcedBlock);
  // indicates to the player that this effect is applied
  player->attachEffect(this);
}

Force::~Force() {
  // indicate to the player that the effect is no longer applied and is deleted
  player->detachEffect(this);
}
