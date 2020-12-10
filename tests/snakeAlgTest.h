#ifndef __SNAKEALGTEST_H__
#define __SNAKEALGTEST_H__

#include "gtest/gtest.h"
#include "../include/Snake.h"
#include "../include/SnakeMovement.h"
#include "../include/Pineapple.h"
#include "../include/PineappleMovement.h"

// draw()
TEST(SnakeTests, draw)
{
    Graphic* snake = new Snake();

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(720, 720, 0, &window, &renderer);

    snake->draw();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    EXPECT_EQ(snake->body[0].second, 330);
    EXPECT_EQ(snake->body[0].first, 360);
}

// Snake runs into pineapple
// Checks if size of snake increases after collision
TEST(SnakeTests, updatePineapple)
{
    Graphic* snake = new Snake();
    Graphic* pineapple = new Pineapple();
    pineapple->collisions += 2;
    snake->update(pineapple);

    EXPECT_EQ(snake->body.size(), 2);
}

// Snake runs into walls
// Checks if size of snake goes back to one after collision
TEST(SnakeTests, updateWalls)
{
    Graphic* snake = new Snake();
    Graphic* pineapple = new Pineapple();

    snake->body[0].first = -1; // Outside the wall
    snake->body[0].second = -1;

    snake->body.push_back(std::make_pair(-1, 19));

    snake->update(pineapple);

    // Snake went back to original spawn point
    EXPECT_EQ(snake->body[0].second, 330);
    EXPECT_EQ(snake->body[0].first, 360);
}

// Snake runs into itself
TEST(SnakeTests, updateSnake)
{
    Graphic* snake = new Snake();
    Graphic* pineapple = new Pineapple();
    
    snake->body.push_back(std::make_pair(360 + 20, 330));
    snake->body.push_back(std::make_pair(360 + 40, 330));

    snake->body[0].first = snake->body[2].first;
    snake->body[0].second = snake->body[2].second;

    snake->update(pineapple);

    // Snake went back to original spawn point
    EXPECT_EQ(snake->body[0].second, 330);
    EXPECT_EQ(snake->body[0].first, 360);
}

// move()
TEST(SnakeTests, move)
{
    Graphic* snake = new Snake();
    snake->direction = "down";

    snake->setMovement(new SnakeMovement());
    snake->move();

    EXPECT_EQ(snake->body[0].second, 330 + SPEED);
    EXPECT_EQ(snake->body[0].first, 360);
}

// setRenderer()
TEST(SnakeTests, setRenderer)
{
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_CreateWindowAndRenderer(720, 720, 0, &window, &renderer);

    Graphic* snake = new Snake();
    snake->setRenderer(renderer);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    ASSERT_TRUE(renderer != nullptr);
}

#endif