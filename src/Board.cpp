#include "../include/Board.h"
#include "../include/Snake.h"
#include "../include/Pineapple.h"
#include <iostream>
// Dimensions of window
const int WINDOW_WIDTH = 720;
const int WINDOW_HEIGHT = 720;

Board::Board() : Graphic()
{
    // Initializes SDL library
    SDL_Init(SDL_INIT_EVERYTHING);

    // Creates window & renderer
    // window = little window that pops up
    // renderer = generates the image thats on the window
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    
    // Gives window a name
    SDL_SetWindowTitle(window, "Snake");
   
    // Creates snake
    snake = new Snake();
    
    // Creates pineapple
    pineapple = new Pineapple();
}

Board::~Board()
{
    // Gets rid of window & render
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void Board::draw()
{
    SDL_Event event; // Holds whichever event takes place during frame

    bool play = true; // Checks if user has quit game

    while (play)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) { play = false; }
            
            // State of keyboard
            // Holds which keys have been pressed
            const Uint8* state = SDL_GetKeyboardState(NULL);

            if (state[SDL_SCANCODE_UP])
            {
                snake->direction = "up";
            } else if (state[SDL_SCANCODE_DOWN])
            {
                snake->direction = "down";
            } else if (state[SDL_SCANCODE_LEFT])
            {
                snake->direction = "left";
            } else if (state[SDL_SCANCODE_RIGHT])
            {
                snake->direction = "right";
            } else if (state[SDL_SCANCODE_ESCAPE])
            {
                play = false;
            }
        }

        // Wraps snake if it goes off screen
        // TEMPORARY
        if (snake->x > 720) { snake->x = 0; }
        else if (snake->x < 0) { snake->x = 720; }
        else if (snake->y > 720) { snake->y = 0; }
        else if (snake->y < 0) { snake->y = 720; }

        snake->update(); // Updates snake's position since last draw call

        // Sets drawing color of entire window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // Clears window to desired color
        SDL_RenderClear(renderer);

        /** Draw snake & food BEFORE SDL_RenderPresent **/
        // Give snake instance the renderer
        snake->setRenderer(renderer);

        // Draws snake at selected location (100, 100)
        snake->draw();

        // Checks whether the snake has collided with the pineapple 
        // and creates a new one if true
        if((snake->x +16 >= pineapple->x && snake->y + 16 >= pineapple->y)
            && (snake->x <= pineapple->x + 10 && snake->y <= pineapple->y + 10))
            {
                pineapple = new Pineapple();
            }

        // pineapple->setRenderer(renderer);
        pineapple->setRenderer(renderer);

        pineapple->draw();
        
        // Renders to window
        SDL_RenderPresent(renderer);

        SDL_Delay(10);
    }

    // Deletes any SDL objects in use
    SDL_Quit();
}
