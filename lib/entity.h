#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include <SDL_keyboard.h>
#include <sdl_init.h>

#define MOVE_STEP 2

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    JUMP,
    ATTACK,
}Move_e;

typedef struct
{
    int x;
    int y;
}Frame_s;

typedef struct
{
    int spirit_frames;
    Frame_s* spirit_array;
}Array_s;

typedef struct
{
    SDL_Rect position;
    SDL_Rect spirit;
    SDL_Texture *texture;
    Window_s *win;
    Array_s *animations;
    int num_animations;
    const Uint8 *keys_array;
}Entity_s;


void ENTITY_Init(Entity_s *name, Window_s *win, char* location);
void ENTITY_Set_Size(Entity_s *name, int w, int h);
void ENTITY_Set_Position(Entity_s *name, int x, int y);
void ENTITY_Animation_Init(Entity_s *name, int num_animation);
void ENTITY_Animation_Spirit_Size(Entity_s *name, int w, int h);
void ENTITY_Animation_Create(Entity_s *name, Move_e animation_name, int frame_num, int y);
void ENTITY_ANIMATION_Show(Entity_s *name, Move_e animation_name, int i);
void ENTITY_Movement(Entity_s *name, int frame_count);

/*
1. How much animations [JUMP, MOVE UP itd] = 5 ==> Array_s animations[5]
2. How much frame each animation have spiritf_frames, name of animation spirit_array

void ENTITY_Create_Animations(Entity_s *name, int )
{

}



*/







#endif /* ENTITY_H */
