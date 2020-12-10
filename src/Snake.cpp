#include "../include/Snake.h"
#include "../include/SnakeMovement.h"

#include <iostream>

// Spawn point of snake
// Point at top left of snake rectangle
// 100 pixels across & down from top left of window
const double SNAKE_SPAWN_X = 360;
const double SNAKE_SPAWN_Y = 330;

// Dimensions of snake
const int SNAKE_WIDTH = 20;
const int SNAKE_HEIGHT = 20;

Snake::Snake() : Graphic()
{
    body.push_back(std::make_pair(SNAKE_SPAWN_X, SNAKE_SPAWN_Y));
}

void Snake::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

void Snake::draw()
{
    for (unsigned i = 0; i < body.size(); i++)
    {
        // Location on board of segement of snake
        SDL_Rect location = {
            static_cast<int>(body[i].first),
            static_cast<int>(body[i].second),
            SNAKE_WIDTH,
            SNAKE_HEIGHT
        };

        // Sets color of snake (white)
        // r, g, b, alpha (opacity)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // Colors the snake
        SDL_RenderFillRect(renderer, &location);
    }
}

void Snake::update(Graphic* pineapple)
{
    // Check for collisions with:
    // - pineapple
    if (pineapple->collisions - body.size() == 1) // New collision
    {
        body.push_back(std::make_pair(body[body.size() - 1].first, body[body.size() - 1].second));
    }
    
    // - walls
    if (body[0].first + 20 > 720 || body[0].second + 20 > 720 || body[0].first < 0 || body[0].second < 0) {
        body.erase(body.begin() + 1, body.end() - 1);
        body[0].first = SNAKE_SPAWN_X;
        body[0].second = SNAKE_SPAWN_Y;
        direction = "";
        pineapple->collisions = 0;
    }

    // - itself
    for (unsigned i = 2; i < body.size(); i++)
    {
        if (body[0].first == body[i].first && body[0].second == body[i].second)
        {
            body.erase(body.begin() + 1, body.end() - 1);
            body[0].first = SNAKE_SPAWN_X;
            body[0].second = SNAKE_SPAWN_Y;
            direction = "";
            pineapple->collisions = 0;
        }
    }

    setMovement(new SnakeMovement());
    movement->move(this);

}
void Snake::move()
{
    if (movement !=nullptr) { movement->move(this);}
}
