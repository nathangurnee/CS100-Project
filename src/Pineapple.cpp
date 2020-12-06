#include "../include/Pineapple.h"
#include "../include/PineappleMovement.h"

// Dimensions of pineapple
const int PINEAPPLE_WIDTH = 10;
const int PINEAPPLE_HEIGHT = 10;

Pineapple::Pineapple() : Graphic(), renderer(NULL)
{
    x = 10 + rand() % 604; 
    y = 10 + rand() % 604;
    collisions = 0;
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
    if((snake->body[0].first + 20 >= x && snake->body[0].second + 20 >= y)
        && (snake->body[0].first <= x + PINEAPPLE_WIDTH && snake->body[0].second <= y + PINEAPPLE_HEIGHT))
    {
        setMovement(new PineappleMovement());
        movement->move(this);

        collisions++;
    }
}