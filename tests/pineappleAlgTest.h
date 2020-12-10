#ifndef PINEAPPLE_TEST_CPP
#define PINEAPPLE_TEST_CPP

#include "gtest/gtest.h"
#include "../include/Pineapple.h"

TEST(PineappleTest, testingConstructor){
    Graphic* pineapple = new Pineapple();
    ASSERT_TRUE(pineapple != nullptr);
}

TEST(PineappleTest, testingLocation) {
    Graphic* pineapple = new Pineapple();
    EXPECT_EQ(pineapple->x, 657);
    EXPECT_EQ(pineapple->y, 606);
}

TEST(PineappleTest, testingRenderer) {
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_CreateWindowAndRenderer(720, 720, 0, &window, &renderer);
    Graphic* pineapple = new Pineapple();
    pineapple->setRenderer(renderer);
    ASSERT_TRUE(pineapple != nullptr);
}


#endif //PINEAPPLE_TEST_CPP