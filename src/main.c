#include <main.h>



/*
1. Init
    win - wchich window to show animation
    Animation_s - spirite choosing
    Texture init
2. Create
    Struct with dynam array and array size
    frame count
    and Y axis


*/




int main(int argc, char *argv[])
{
    Window_s win;
    Animation_s anime_player;
    Player_s player;
    Array_s MOVE_UP;
    Array_s MOVE_DOWN;
    Array_s MOVE_LEFT;
    Array_s MOVE_RIGHT;
    
   
    SDL_INIT_All(&win);
    ANIMATION_Init(&win, &anime_player, 64, 64, "C:/Users/ppdra/Desktop/Game/textures/player/player.png");
    ANIMATION_Create(&anime_player, &MOVE_UP, 9, 512);
    ANIMATION_Create(&anime_player, &MOVE_LEFT, 9, 576);
    ANIMATION_Create(&anime_player, &MOVE_DOWN, 9, 640);
    ANIMATION_Create(&anime_player, &MOVE_RIGHT, 9, 704);

    Array_s animations[4] = {MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT};

    PLAYER_Ctor(&player, 0, 0, 0, 0);
    PLAYER_Set_Size(&player, 64, 64);
    PLAYER_Set_Position(&player, 0, 0);
   
    const int FRAME_TIME = 16; /* 16.66 ms*/
    int FRAME_COUNT = 0;
    const Uint32 ANIMATION_TIME = 111;  /* ms*/
    Uint32 current_time = 0;
    
    
    
    
    SDL_Event event;
    Uint32 lastUpdate = SDL_GetTicks();

    while(1)
    {
        Uint32 start_frame_cap = SDL_GetTicks();
        
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }
        SDL_RenderClear(win.render);
        
        Uint32 start_animation = SDL_GetTicks();
        Uint32 delta_anim = start_animation - lastUpdate;
        current_time += delta_anim;
        lastUpdate = start_frame_cap;
        



        if (current_time >= ANIMATION_TIME)
        {
            current_time = 0;
            FRAME_COUNT++;
            if(FRAME_COUNT == 8)
            {
                FRAME_COUNT = 0;
            }
        }
    
        PLAYER_Move(&player, &anime_player, animations, FRAME_COUNT);
        SDL_RenderCopy(win.render, anime_player.texture, &anime_player.origin, &player.position);  
        SDL_RenderPresent(win.render);




        Uint32 end_frame_cap = SDL_GetTicks();
        Uint32 time_passed = end_frame_cap - start_frame_cap;
        if(time_passed < FRAME_TIME)
        {
            uint32_t frame_delay = FRAME_TIME - time_passed;
            SDL_Delay(frame_delay);
        }
    } 
return 0;
}

