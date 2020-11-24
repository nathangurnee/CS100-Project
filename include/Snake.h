#ifndef SNAKE_H
#define SNAKE_H

#include "Graphic.h"

// Spawn point of snake
// Point at top left of snake rectangle
// 100 pixels across & down from top left of window
const int SNAKE_SPAWN_X = 100;
const int SNAKE_SPAWN_Y = 100;

class Snake: public Graphic
{
public:
    Snake()
        : Graphic(), renderer(NULL), x(SNAKE_SPAWN_X), y(SNAKE_SPAWN_Y) {}
    virtual void setRenderer(SDL_Renderer*);
    virtual void draw();
private:
    SDL_Renderer* renderer; // What does the drawing
    int x, y; // Coordinates
};

#endif