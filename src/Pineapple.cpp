#include "../include/Pineapple.h"

// Dimensions of pineapple
const int PINEAPPLE_WIDTH = 16;
const int PINEAPPLE_HEIGHT = 16;

void Pineapple::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

void Pineapple::draw()
{
    // x, y = coordinates
    SDL_Rect location = { x, y, PINEAPPLE_WIDTH, PINEAPPLE_HEIGHT };

    // Sets color of pineapple (white)
    // r, g, b, alpha (opacity)
    SDL_SetRenderDrawColor(renderer, 200, 255, 18, 255);

    // Colors the pineapple
    SDL_RenderFillRect(renderer, &location);
}