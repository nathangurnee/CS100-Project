#ifndef SNAKE_H
#define SNAKE_H

#include "Graphic.h"

class Snake: public Graphic
{
public:
    Snake();
    virtual void setRenderer(SDL_Renderer*);
    virtual void draw();
    virtual void update(Graphic*);
private:
    SDL_Renderer* renderer;
};

#endif