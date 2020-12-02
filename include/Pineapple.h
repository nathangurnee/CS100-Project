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
        : Graphic(), renderer(NULL) {
            x = rand() % 720;
            y = rand() % 720;
        }
    virtual void setRenderer(SDL_Renderer*);
    virtual void draw();
private:
    SDL_Renderer* renderer; // What does the drawing
    int x, y; // Coordinates
};

#endif