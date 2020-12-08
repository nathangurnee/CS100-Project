#include "../include/Image.h"

// Declare static member
Image* Image::image = nullptr;

Image::Image(const std::string& file) : file(file)
{
    // Loads the image into a surface object
    surface = SDL_LoadBMP(file.c_str());
}

Image::~Image()
{
    SDL_FreeSurface(surface); // Deletes surface object
    delete image;
    image = nullptr;    
}

Image* Image::getImage(const std::string& file)
{
    // Creates the Image Singleton
    if (image == nullptr) { image = new Image(file); }

    return image;
}