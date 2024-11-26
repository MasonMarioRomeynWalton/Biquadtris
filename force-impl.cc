module concrete_effects;

import player;

Force::Force(char forcedBlock): forcedBlock{forcedBlock} {
  player->setNextBlock(forcedBlock);
} 

Force::~Force() {}
