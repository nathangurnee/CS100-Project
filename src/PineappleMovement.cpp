#include "../include/PineappleMovement.h"

void PineappleMovement::move(Graphic* pineapple)
{
    pineapple->x = 10 + rand() % 704; 
    pineapple->y = 10 + rand() % 704;
}