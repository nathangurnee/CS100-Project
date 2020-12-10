#ifndef IMAGE_TEST_CPP
#define IMAGE_TEST_CPP

#include "gtest/gtest.h"
#include "../include/Image.h"

TEST(ImageTest, testingConstructor){
    Image* image = Image::getImage("BobImg.bmp");
    ASSERT_TRUE(image != nullptr);
}

TEST(ImageTest, testGetImage) {
    Image* image = Image::getImage("BobImg.bmp");
    EXPECT_EQ(image, Image::getImage("BobImg.bmp"));
}

#endif //IMAGE_TEST_CPP