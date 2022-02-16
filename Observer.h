#ifndef ESEMPIO_OBSERVER_H
#define ESEMPIO_OBSERVER_H


class Observer {
public:

    virtual  ~Observer() {}

    virtual void update() = 0;
};

#endif //ESEMPIO_OBSERVER_H
