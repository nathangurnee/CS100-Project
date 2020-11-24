#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "SDL.h"

class Graphic
{
public:
    Graphic() {};
    virtual void setRenderer(SDL_Renderer*) {}
    virtual void draw() = 0;
};

#endif