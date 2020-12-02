#ifndef SNAKE_H
#define SNAKE_H

#include "Graphic.h"

// Spawn point of snake
// Point at top left of snake rectangle
// 100 pixels across & down from top left of window
const double SNAKE_SPAWN_X = 100;
const double SNAKE_SPAWN_Y = 100;

class Snake: public Graphic
{
public:
    Snake() : Graphic(), x(SNAKE_SPAWN_X), y(SNAKE_SPAWN_Y) {}
    virtual void setRenderer(SDL_Renderer*);
    virtual void draw();
    virtual void update();
    virtual double getX() const { return x; }
    virtual double getY() const { return y; }
    virtual std::string getDirection() const { return direction; }
    virtual void setX(double x) { this->x = x; }
    virtual void setY(double y) { this->y = y; }
    virtual void setDirection(const std::string&);
private:
    SDL_Renderer* renderer;
    double x, y;
    std::string direction;
};

#endif