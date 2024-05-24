#include <animation.h>

void ANIMATION_Set_TextureIMG(Window_s *win, Animation_t* animation, const char *location)
{
    animation->texture = IMG_LoadTexture(win->render, location);
}

void ANIMATION_Cut_Sprite(SDL_Rect *origin, int w, int h)
{
    origin->w = w;
    origin->h = h;
}



void ANIMATION_Init_Up(Animation_t *animation)
{
    for(uint8_t i = 0; i < ANIMATION_SIZE; i++)
    {
        animation->ANIMATION_up[i].x = i * (animation->origin.w);
        animation->ANIMATION_up[i].y = 512;
    }
}

void ANIMATION_Init_Down(Animation_t *animation)
{
    for(uint8_t i = 0; i < ANIMATION_SIZE; i++)
    {
        animation->ANIMATION_up[i].x = i * (animation->origin.w);
        animation->ANIMATION_up[i].y = 704;
    }
}

void ANIMATION_Init_Left(Animation_t *animation)
{
    for(uint8_t i = 0; i < ANIMATION_SIZE; i++)
    {
        animation->ANIMATION_up[i].x = i * (animation->origin.w);
        animation->ANIMATION_up[i].y = 576;   
    }

}

void ANIMATION_Init_Right(Animation_t *animation)
{
    for(uint8_t i = 0; i < ANIMATION_SIZE; i++)
    {
        animation->ANIMATION_up[i].x = i * (animation->origin.w);
        animation->ANIMATION_up[i].y = 640;
    }
}

void ANIMATION_Up(Animation_t *animation, uint8_t i)
{
    animation->origin.x = animation->ANIMATION_up[i].x;
    animation->origin.y = animation->ANIMATION_up[i].y;
}

void ANIMATION_Down(Animation_t *animation, uint8_t i)
{
    animation->origin.x = animation->ANIMATION_down[i].x;
    animation->origin.y = animation->ANIMATION_down[i].y;
}

void ANIMATION_Left(Animation_t *animation, uint8_t i)
{
    animation->origin.x = animation->ANIMATION_left[i].x;
    animation->origin.y = animation->ANIMATION_left[i].y;
}

void ANIMATION_Right(Animation_t *animation, uint8_t i)
{
    animation->origin.x = animation->ANIMATION_right[i].x;
    animation->origin.y = animation->ANIMATION_right[i].y;
}