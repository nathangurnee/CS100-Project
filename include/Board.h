#ifndef BOARD_H
#define BOARD_H

#include "Graphic.h"

class Board: public Graphic
{
public:
    Board();
    ~Board();
    virtual void draw();
private:
    Graphic* snake;
    Graphic* pineapple;
    SDL_Window* window; // Where we're drawing to
    SDL_Renderer* renderer; // What does the drawing
};

#endif