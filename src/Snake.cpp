#include "../include/Snake.h"
#include "../include/SnakeMovement.h"

// Spawn point of snake
// Point at top left of snake rectangle
// 100 pixels across & down from top left of window
const double SNAKE_SPAWN_X = 100;
const double SNAKE_SPAWN_Y = 100;

// Dimensions of snake
const int SNAKE_WIDTH = 16;
const int SNAKE_HEIGHT = 16;

Snake::Snake() : Graphic()
{
    x = SNAKE_SPAWN_X;
    y = SNAKE_SPAWN_Y;
}

void Snake::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

void Snake::draw()
{
    // x, y = coordinates
    SDL_Rect location = {
        static_cast<int>(x),
        static_cast<int>(y),
        SNAKE_WIDTH,
        SNAKE_HEIGHT
    };

    // Sets color of snake (white)
    // r, g, b, alpha (opacity)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Colors the snake
    SDL_RenderFillRect(renderer, &location);
}

void Snake::update()
{
    setMovement(new SnakeMovement());
    movement->move(this);
}