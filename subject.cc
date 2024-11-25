export module subject;

import observer;
import <vector>;

//class Observer; // forward declaration


export class Subject {
    std::vector<Observer*> observers;
 public:
  void attach( Observer* o );
  void detach( Observer* o );
  void notifyObservers();
  virtual ~Subject();
};

