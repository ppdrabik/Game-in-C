#include <main.h>






int main(int argc, char *argv[])
{
    Window_s win;
    Player_s player;
    SDL_INIT_All(&win);
    ANIMATION_Set_TextureIMG(&win, &player.animate, "C:/Users/ppdra/Desktop/Game/textures/player/player.png");
    ANIMATION_Cut_Sprite(&player.animate.origin, 64, 64);
    ANIMATION_Init_Up(&player.animate);
    ANIMATION_Init_Down(&player.animate);
    ANIMATION_Init_Left(&player.animate);
    ANIMATION_Init_Right(&player.animate);
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
            if(FRAME_COUNT == 9)
            {
                FRAME_COUNT = 0;
            }
        }
        ANIMATION_Up(&player.animate, FRAME_COUNT);

        PLAYER_Move(&player);
        SDL_RenderCopy(win.render, player.animate.texture, &player.animate.origin, &player.position);  
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

