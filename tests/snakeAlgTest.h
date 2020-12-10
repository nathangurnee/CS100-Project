#ifndef __SNAKEALGTEST_H__
#define __SNAKEALGTEST_H__

#include "gtest/gtest.h"

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

#endif
