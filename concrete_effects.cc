export module concrete_effects;

import effects;
import player;

export class Blind: public Effect {
  Player* player;
 public:
  Blind(Player* player);
  ~Blind();
};

export class Heavy: public Effect {
  int addedWeight;
  Player* player;
 public:
  Heavy(Player* player);
  ~Heavy();
};

export class Force: public Effect {
  Player* player;
 public:
  Force(char forcedBlock, Player* player);
  ~Force();
};
