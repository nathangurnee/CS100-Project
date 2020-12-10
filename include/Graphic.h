#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <deque>
#include <string>
#include <utility>
#include "SDL.h"
#include "Movement.h"

// Speed of the snake
const double SPEED = 3.5;

class Movement; // Forward declare Movement class to make member variable

class Graphic
{
public:
    Graphic() {}
    virtual void setRenderer(SDL_Renderer*) {}
    virtual void draw() = 0;
    virtual void update(Graphic*) {}
    void setMovement(Movement* movement) { this->movement = movement; }
    virtual void move() {}
    double x, y; // Coordinates
    std::string direction;
    int collisions; // Holds number of collisions between snake & pineapple
    std::deque<std::pair<double, double>> body; // Snake
protected:
    Movement* movement;
};

#endif
