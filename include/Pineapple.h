#ifndef PINEAPPLE_H
#define PINEAPPLE_H

#include "Graphic.h"
#include <stdlib.h>

// Spawn point of pineapple (randomly based on time)
// Point at top left of pineapple rectangle

class Pineapple: public Graphic
{
public:
    Pineapple();
    virtual void setRenderer(SDL_Renderer*);
    virtual void draw();
    virtual void update(Graphic*);
    virtual void move();
private:
    SDL_Renderer* renderer; // What does the drawing
};

#endif