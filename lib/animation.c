#include <animation.h>


static void ANIMATION_Set_TextureIMG(Window_s *win, Animation_s* animation, const char *location);
static void ANIMATION_Cut_Sprite(SDL_Rect *origin, int w, int h);



static void ANIMATION_Set_TextureIMG(Window_s *win, Animation_s* animation, const char *location)
{
    animation->texture = IMG_LoadTexture(win->render, location);
}

static void ANIMATION_Cut_Sprite(SDL_Rect *origin, int w, int h)
{
    origin->w = w;
    origin->h = h;
}


/*
w,h - cut texture to given size, should contain only one entity

*/
void ANIMATION_Init(Window_s *win, Animation_s *name, int w, int h, const char *location)
{
    ANIMATION_Set_TextureIMG(win, name, location);
    ANIMATION_Cut_Sprite(&name->origin, w, h);
}

void ANIMATION_Create(Animation_s *name, Array_s *array, int frame_count, int y)
{
    array->frame_count = frame_count;
    array->animation_name =(Frame_s*)malloc(sizeof(Frame_s) * array->frame_count);

    for(uint8_t i = 0; i < array->frame_count - 1; i++)
    {
        array->animation_name[i].x = i * (name->origin.w);
        array->animation_name[i].y = y;
    }
}

void ANIMATION_Show(Animation_s *animation, Array_s *array, int index, int i)
{
    
    animation->origin.x = array[index].animation_name[i].x;
    animation->origin.y = array[index].animation_name[i].y;
}

