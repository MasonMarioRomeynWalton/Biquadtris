export module blocks;

import <vector>;
import <utility>;

export class Blocks {
 public:
  std::vector<std::pair<int,int>> coords;
 public:
  virtual int clearRow(int i) = 0;
  virtual std::vector<std::pair<int,int>> rotate(char dir) = 0;
  virtual std::vector<std::pair<int,int>> translate(char dir) = 0;
  virtual std::vector<std::pair<int,int>> getCoords() = 0;
  virtual void setCoords(std::vector<std::pair<int,int>> newCoords) = 0;
  virtual ~Blocks();
};
  
export class NoBlocks: public Blocks {
   protected:
    std::vector<std::pair<int,int>> coords;
   public:
    NoBlocks();
    int clearRow(int i);
    std::vector<std::pair<int,int>> rotate(char dir);
    std::vector<std::pair<int,int>> translate(char dir);
    std::vector<std::pair<int,int>> getCoords();
    void setCoords(std::vector<std::pair<int,int>> newCoords);
};

export class Decorator: public Blocks {
   public:
    std::vector<std::pair<int,int>> coords;
    Blocks* component;
   public:
    Decorator(Blocks* base);
    virtual ~Decorator() {delete component;}
    virtual int clearRow(int i) = 0;
    virtual std::vector<std::pair<int,int>> rotate(char dir) = 0;
    virtual std::vector<std::pair<int,int>> translate(char dir) = 0;
    virtual std::vector<std::pair<int,int>> getCoords() = 0;
    virtual void setCoords(std::vector<std::pair<int,int>> newCoords) = 0;
};
