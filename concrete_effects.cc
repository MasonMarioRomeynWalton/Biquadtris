export module concrete_effects;

import effects;
import player;

export class Blind: public Effect {
  Player* player;
 public:
  Blind(Player* player);
  virtual ~Blind() override;
};

export class Heavy: public Effect {
  int addedWeight;
  Player* player;
 public:
  Heavy(Player* player);
  virtual ~Heavy() override;
};

export class Force: public Effect {
  Player* player;
 public:
  Force(char forcedBlock, Player* player);
  virtual ~Force() override;
};
