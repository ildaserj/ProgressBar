//
// Created by serja on 09/12/2021.
//

#ifndef ESEMPIO_SUBJECT_H
#define ESEMPIO_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notify() = 0;
    virtual  ~Subject() {};
};


#endif //ESEMPIO_SUBJECT_H
