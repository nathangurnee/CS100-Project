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
    virtual double getX() const {}
    virtual double getY() const {}
    virtual std::string getDirection() const {}
    virtual void setX(double) {}
    virtual void setY(double) {}
    virtual void setDirection(const std::string&) {}
    void setMovement(Movement* movement) { this->movement = movement; }
protected:
    Movement* movement;
};

#endif