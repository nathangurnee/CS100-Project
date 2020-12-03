#include "../include/SnakeMovement.h"

void SnakeMovement::move(Graphic* snake)
{
    if (snake->direction == "up")
    {
        snake->y -= SPEED;
    } else if (snake->direction == "down")
    {
        snake->y += SPEED;
    } else if (snake->direction == "left")
    {
        snake->x -= SPEED;
    } else if (snake->direction == "right")
    {
        snake->x += SPEED;
    }
}