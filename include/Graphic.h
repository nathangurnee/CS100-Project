#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <string>
#include "SDL.h"
#include "Movement.h"

// Speed of the snake
const double SPEED = 2.5;

class Movement; // Forward declare Movement class to make member variable

class Graphic
{
public:
    Graphic() {}
    virtual void setRenderer(SDL_Renderer*) {}
    virtual void draw() = 0;
    virtual void update() {}
    void setMovement(Movement* movement) { this->movement = movement; }
    double x, y; // Coordinates
    std::string direction;
protected:
    Movement* movement;
};

#endif