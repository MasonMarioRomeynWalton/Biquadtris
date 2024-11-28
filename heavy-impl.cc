module concrete_effects;

import player;
import level;
import concrete_levels;

Heavy::Heavy(int addedWeight): addedWeight{addedWeight} {
  player->opponent->level->addWeight(addedWeight);
}

Heavy::~Heavy() {
  player->level->addWeight(0-addedWeight);
}
