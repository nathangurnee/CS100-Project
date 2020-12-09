#include "../include/SnakeMovement.h"

void SnakeMovement::move(Graphic* snake)
{
    snake->body.pop_back();
    double x = snake->body[0].first;
    double y = snake->body[0].second;

    if (snake->direction == "up")
    { 
        y -= SPEED;
    } else if (snake->direction == "down")
    {
        y += SPEED;
    } else if (snake->direction == "left")
    {
        x -= SPEED;
    } else if (snake->direction == "right")
    {
        x += SPEED;
    }

    snake->body.push_front(std::make_pair(x, y));    
}