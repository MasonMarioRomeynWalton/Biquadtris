module concrete_effects;

import player;
import level;
import concrete_levels;

Heavy::Heavy(int addedWeight, Player* player): addedWeight{addedWeight}, player{player} {
  player->getOpponent()->getLevel()->addWeight(addedWeight);
}

Heavy::~Heavy() {
  player->getLevel()->addWeight(0-addedWeight);
}
