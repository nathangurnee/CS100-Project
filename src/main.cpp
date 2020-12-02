#include "../include/Board.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand((unsigned)time(0));
    Graphic* game = new Board();
    game->draw();
}
