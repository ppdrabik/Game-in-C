#include <sdl_init.h>


void SDL_INIT_All(Window_s *window)
{
//SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
SDL_Init(SDL_INIT_EVERYTHING);
window->win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
window->render = SDL_CreateRenderer(window->win, -1, 0); /* -1 to chose fastest rendering driver */
IMG_Init(IMG_INIT_PNG);
}