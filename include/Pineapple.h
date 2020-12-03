#ifndef PINEAPPLE_H
#define PINEAPPLE_H

#include "Graphic.h"
#include <stdlib.h>

// Spawn point of pineapple (randomly based on time)
// Point at top left of pineapple rectangle

class Pineapple: public Graphic
{
public:
    Pineapple()
        : Graphic(), renderer(NULL), x(10 + rand() % 704), y(10 + rand() % 704) {}
    virtual void setRenderer(SDL_Renderer*);
    virtual void draw();
    virtual double getX() const {return x;}
    virtual double getY() const {return y;}
private:
    SDL_Renderer* renderer; // What does the drawing
    double x, y; // Coordinates
};

#endif