module concrete_effects;

import player;
import level;
import concrete_levels;
import effects;

// Constructor
Heavy::Heavy(Player* player): addedWeight{2}, player{player} {
  // increase the heaviness of the current level
  player->getLevel()->addWeight(addedWeight);
  // Indicate to a player that this effect is applied
  player->attachEffect(this);
}

// Destructor
Heavy::~Heavy() {
  // Indicate to the player that the effect is no longer applied and delete it
  player->getLevel()->addWeight(0-addedWeight);
  player->detachEffect(this);
}

