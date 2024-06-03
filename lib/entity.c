#include <entity.h>
#include <stdio.h>

void ENTITY_Init(Entity_s *name, Window_s *win, char* location)
{
    name->position.x = 0;
    name->position.y = 0;
    name->position.w = 0;
    name->position.h = 0;
    name->spirit.x = 0;
    name->spirit.y = 0;
    name->spirit.w = 0;
    name->spirit.h = 0;
    name->num_animations = 0;
    name->win = win;
    name->texture = IMG_LoadTexture(name->win->render, location);
    name->animations = NULL;
    name->keys_array = SDL_GetKeyboardState(NULL);
}


void ENTITY_Set_Size(Entity_s *name, int w, int h)
{
    name->position.w = w;
    name->position.h = h;
}


void ENTITY_Set_Position(Entity_s *name, int x, int y)
{
    name->position.x = x;
    name->position.y = y;
}


void ENTITY_Animation_Init(Entity_s *name, int num_animation)
{
    name->num_animations = num_animation;
    name->animations = (Array_s*)malloc(num_animation * sizeof(Array_s));
    for (int i = 0; i < num_animation; i++) 
    {
        name->animations[i].spirit_frames = 0;
        name->animations[i].spirit_array = NULL;
    }
}


void ENTITY_Animation_Spirit_Size(Entity_s *name, int w, int h)
{
    name->spirit.w = w;
    name->spirit.h = h;
}


void ENTITY_Animation_Create(Entity_s *name, Move_e animation_name, int frame_num, int y)
{
    name->animations[animation_name].spirit_frames = frame_num;
    name->animations[animation_name].spirit_array = (Frame_s*)malloc(frame_num * sizeof(Frame_s));
    for(uint8_t i = 0; i < frame_num; i++)
    {
        name->animations[animation_name].spirit_array[i].x = i * (name->spirit.w);
        name->animations[animation_name].spirit_array[i].y = y;

    }
}


void ENTITY_ANIMATION_Show(Entity_s *name, Move_e animation_name, int i)
{
    name->spirit.x = name->animations[animation_name].spirit_array[i].x;
    name->spirit.y = name->animations[animation_name].spirit_array[i].y;
}

void ENTITY_Movement(Entity_s *name, int frame_count)
{
    if(name->keys_array[SDL_SCANCODE_W] == 1)
    {
        if(name->position.y > 0)
        {
           ENTITY_Set_Position(name, name->position.x, (name->position.y) - MOVE_STEP); 
        }
    }
    
    if(name->keys_array[SDL_SCANCODE_S] == 1)
    {
        if(name->position.y < WINDOW_HEIGHT - name->position.w)
        {
            ENTITY_Set_Position(name, name->position.x, (name->position.y) + MOVE_STEP);
        }
    }


    if(name->keys_array[SDL_SCANCODE_A] == 1)
    {
        if(name->position.x > 0)
        {
            ENTITY_Set_Position(name, (name->position.x) - MOVE_STEP, name->position.y);
        }    
    }

    if(name->keys_array[SDL_SCANCODE_D] == 1)
    {
        if (name->position.x < WINDOW_WIDTH - name->position.h)
        {
           ENTITY_Set_Position(name, (name->position.x) + MOVE_STEP, name->position.y); 
        }
    }
}