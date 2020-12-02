#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Graphic.h"

class Graphic;

class Movement
{
public:
    Movement() {}
    virtual void move(Graphic*) = 0;
};

#endif