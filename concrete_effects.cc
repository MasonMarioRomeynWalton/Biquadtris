export module concrete_effects;

import player;

class Blind {
  Player* player;
 public:
  Blind();
  ~Blind();
};

class Heavy {
  int addedWeight;
  Player* player;
 public:
  Heavy(int addedWeight);
  ~Heavy();
};

class Force {
  char forcedBlock;
  Player* player;
 public:
  Force(char forcedBlock);
  ~Force();
};
