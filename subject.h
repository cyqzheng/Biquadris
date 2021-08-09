#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <string>

class Observer;

class Subject {
 protected:
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);
  std::string getObserverNames() const;
};

#endif

