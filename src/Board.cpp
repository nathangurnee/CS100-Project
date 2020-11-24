#include "../include/Board.h"
#include "../include/Snake.h"

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
            if (event.type == SDL_QUIT) { play = false; } // Hit 'X' button
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

        // food->setRenderer(renderer);

        // food->draw();

        // Renders to window
        SDL_RenderPresent(renderer);
    }

    // Deletes any SDL objects in use
    SDL_Quit();
}