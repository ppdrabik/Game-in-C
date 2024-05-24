#ifndef SDL_INIT_H
#define SDL_INIT_H

#include <SDL.h>
#include <SDL_image.h>


#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define FPS 60


typedef struct
{
    SDL_Window *win;
    SDL_Renderer *render;
}Window_s;


void SDL_INIT_All(Window_s *window);


















#endif /* SDL_INIT_H */