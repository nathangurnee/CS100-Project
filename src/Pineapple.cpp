#include "../include/Pineapple.h"
#include "../include/PineappleMovement.h"

// Dimensions of pineapple
const int PINEAPPLE_WIDTH = 10;
const int PINEAPPLE_HEIGHT = 10;

Pineapple::Pineapple() : Graphic(), renderer(NULL)
{
    x = 10 + rand() % 704; 
    y = 10 + rand() % 704;
}

void Pineapple::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

void Pineapple::draw()
{
    // x, y = coordinates
    SDL_Rect location = { static_cast<int>(x), static_cast<int>(y), PINEAPPLE_WIDTH, PINEAPPLE_HEIGHT };

    // Sets color of pineapple (white)
    // r, g, b, alpha (opacity)
    SDL_SetRenderDrawColor(renderer, 200, 255, 18, 255);

    // Colors the pineapple
    SDL_RenderFillRect(renderer, &location);
}

void Pineapple::update(Graphic* snake)
{
    // Checks whether the snake has collided with the pineapple 
    // and creates a new one if true
    if((snake->x +16 >= x && snake->y + 16 >= y)
        && (snake->x <= x + 10 && snake->y <= y + 10))
    {
        setMovement(new PineappleMovement());
        movement->move(this);
    }
}