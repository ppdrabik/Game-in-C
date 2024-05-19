#include <main.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768


int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    
    SDL_Event event;
    while(1)
    {
        SDL_PollEvent(&event);
        if (SDL_HasEvent(SDL_QUIT) == SDL_TRUE)
        {
            break;
        }
    }
    return 0;
}