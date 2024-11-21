export module subject;

import observer;
import <vector>;

//class Observer; // forward declaration


export class Subject {
    //Observer* observers;
    //Problem with next one
    std::vector<Observer*> observers;
    //std::vector<int> observers;
 public:
  void attach( Observer* o );
  void detach( Observer* o );
  void notifyObservers();
  virtual ~Subject();
};

