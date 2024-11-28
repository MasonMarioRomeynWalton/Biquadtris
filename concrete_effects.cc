export module concrete_effects;

import player;

export class Blind {
  Player* player;
 public:
  Blind(Player* player);
  ~Blind();
};

export class Heavy {
  int addedWeight;
  Player* player;
 public:
  Heavy(int addedWeight, Player* player);
  ~Heavy();
};

export class Force {
  Player* player;
 public:
  Force(char forcedBlock, Player* player);
  ~Force();
};
