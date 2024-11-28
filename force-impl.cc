module concrete_effects;

import player;

Force::Force(char forcedBlock, Player* player): player{player} {
  player->setNextBlock(forcedBlock);
}

Force::~Force() {}
