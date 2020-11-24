#include "../include/Snake.h"

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
    SDL_Rect location = { x, y, SNAKE_WIDTH, SNAKE_HEIGHT };

    // Sets color of snake (white)
    // r, g, b, alpha (opacity)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Colors the snake
    SDL_RenderFillRect(renderer, &location);
}