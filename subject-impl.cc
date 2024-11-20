module subject;
//#include "subject.cc"

//std::vector<Observer*> x = std::vector<Observer*>{};


/*import observer;
import <vector>;

class Subject {
    
  public:
    void attach( Observer* o );
    void detach( Observer* o );
    void notifyObservers();
    virtual ~Subject();
  private:
    std::vector<Observer*> observers;
};
*/

void Subject::attach( Observer* o ) {
  observers.emplace_back(o);
}

void Subject::detach( Observer* o ) {
  for (auto it = observers.begin(); it != observers.end();) {
    if (*it == o) it = observers.erase(it);
    else ++it;
  }
}

void Subject::notifyObservers() {
  for (auto o : observers) o->notify(); 
} 

Subject::~Subject() {
   for (auto p : observers)
   {
     delete p;
   } 
   observers.clear();
};

