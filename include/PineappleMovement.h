#ifndef PINEAPPLE_MOVEMENT_H
#define PINEAPPLE_MOVEMENT_H

#include "Movement.h"

class PineappleMovement: public Movement
{
public:
    PineappleMovement() : Movement() {}
    virtual void move(Graphic*);
};

#endif