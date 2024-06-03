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
    Entity_s player;


    SDL_INIT_All(&win);
    ENTITY_Init(&player, &win, "C:/Users/ppdra/Desktop/Game/textures/player/player.png");
    ENTITY_Set_Size(&player, 64, 64);

    ENTITY_Animation_Spirit_Size(&player, 64, 64);
    ENTITY_Animation_Init(&player, 2);
    ENTITY_Animation_Create(&player, UP, 9, 0);
    ENTITY_Animation_Create(&player, DOWN, 9, 64);

    

    
   
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

        ENTITY_Movement(&player, 0);
        ENTITY_ANIMATION_Show(&player, UP, FRAME_COUNT);
        SDL_RenderCopy(win.render, player.texture, &player.spirit, &player.position);  
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

