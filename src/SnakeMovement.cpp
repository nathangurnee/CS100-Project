#include "../include/SnakeMovement.h"

void SnakeMovement::move(Graphic* snake)
{
    double y = snake->getY();
    double x = snake->getX();
    std::string direction = snake->getDirection();
    
    if (direction == "up")
    {
        y -= SPEED;
        snake->setY(y);
    } else if (direction == "down")
    {
        y += SPEED;
        snake->setY(y);
    } else if (direction == "left")
    {
        x -= SPEED;
        snake->setX(x);
    } else if (direction == "right")
    {
        x += SPEED;
        snake->setX(x);
    }
}