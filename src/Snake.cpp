#include "../include/Snake.h"
#include "../include/SnakeMovement.h"

// Dimensions of snake
const int SNAKE_WIDTH = 16;
const int SNAKE_HEIGHT = 16;

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

void Snake::setDirection(const std::string& direction)
{
    this->direction = direction;
}