#include "subject.h"
#include "observer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

std::string Subject::getObserverNames() const {
    vector <string> names;
    int length = observers.size();
    
    for(int i = 0; i < length; i++) { // add all names into the vector
        names.emplace_back(observers[i]->getName());
    }
    // sort
    for(int i = 0; i < length; i++) {
        for(int j = i; j < length; j++) {
            if(names[i] > names[j]) {
                string temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
    // make it into a string to return
    string res = "";
    for(int i = 0; i < length; i++) {
        res += names[i];
        if (i != length - 1) res += ", ";
    }
    return res;
}

