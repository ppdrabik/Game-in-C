#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include <sdl_init.h>

#define ANIMATION_SIZE 9

typedef struct
{
    int x;
    int y;
}Frame_t;

typedef struct
{
    SDL_Rect origin;
    SDL_Texture *texture;
    Frame_t ANIMATION_up[ANIMATION_SIZE];
    Frame_t ANIMATION_down[ANIMATION_SIZE];
    Frame_t ANIMATION_left[ANIMATION_SIZE];
    Frame_t ANIMATION_right[ANIMATION_SIZE];
}Animation_t;

void ANIMATION_Set_TextureIMG(Window_s *win, Animation_t* animation, const char *location);
void ANIMATION_Cut_Sprite(SDL_Rect *origin, int w, int h);
void ANIMATION_Init_Up(Animation_t *animation);
void ANIMATION_Init_Down(Animation_t *animation);
void ANIMATION_Init_Left(Animation_t *animation);
void ANIMATION_Init_Right(Animation_t *animation);
void ANIMATION_Up(Animation_t *animation, uint8_t i);

#endif /* ANIMATION_H */
