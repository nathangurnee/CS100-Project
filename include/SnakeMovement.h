#ifndef SNAKE_MOVEMENT_H
#define SNAKE_MOVEMENT_H

#include "Movement.h"

class SnakeMovement : public Movement
{
public:
    SnakeMovement() : Movement() {}
    virtual void move(Graphic*);
};

#endif