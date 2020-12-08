#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "SDL.h"

class Image
{
public:
    ~Image();
    Image(Image& other) = delete;
    void operator=(const Image& image) = delete;
    static Image* getImage(const std::string&);
    SDL_Surface* surface;
private:
    Image(const std::string&);
    std::string file;
    static Image* image;
};

#endif