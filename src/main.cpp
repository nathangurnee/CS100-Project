#include "../include/Board.h"

int main()
{
    Graphic* game = new Board();

    game->draw();

    delete game;
    game = NULL;
}