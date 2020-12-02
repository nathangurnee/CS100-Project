#include "../include/Board.h"
#include "../include/Snake.h"
#include "../include/Pineapple.h"

// Dimensions of window
const int WINDOW_WIDTH = 720;
const int WINDOW_HEIGHT = 720;

Board::Board() : Graphic()
{
    // Initializes SDL library

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
            if (event.type == SDL_QUIT) // Hit 'X' button
            {
                play = false;
            } else if (event.type = SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE) // Hit 'escape' key
                {
                    play = false;
                }
            }
        }

        // Sets drawing color of entire window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // Clears window to desired color
        SDL_RenderClear(renderer);

        /** Draw snake & food BEFORE SDL_RenderPresent **/
        // Give snake instance the renderer
        snake->setRenderer(renderer);

        // Draws snake at selected location (100, 100)
        snake->draw();

        // pineapple->setRenderer(renderer);
        pineapple->setRenderer(renderer);

        // food->draw();
        pineapple->draw();
        // Renders to window
        SDL_RenderPresent(renderer);
    }

    // Deletes any SDL objects in use
    SDL_Quit();
}