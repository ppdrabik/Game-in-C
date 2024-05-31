#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include <sdl_init.h>



typedef struct
{
    int x;
    int y;
}Frame_s;

typedef struct
{
    int frame_count;
    Frame_s *animation_name;
}Array_s;

typedef struct
{
    SDL_Rect origin;
    SDL_Texture *texture;
}Animation_s;


void ANIMATION_Init(Window_s *win, Animation_s *name, int w, int h, const char *location);
void ANIMATION_Create(Animation_s *name, Array_s *array, int frame_count, int y);
void ANIMATION_Show(Animation_s *animation, Array_s *array, int index, int i);


#endif /* ANIMATION_H */
