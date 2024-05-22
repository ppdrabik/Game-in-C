#include <main.h>




int main(int argc, char *argv[])
{
    Window_s win;
    Player_s player;
    SDL_INIT_All(&win);
    PLAYER_Ctor(&player, player.texture, 0, 0, 100, 100);
    player.texture = IMG_LoadTexture(win.render, "C:/Users/ppdra/Desktop/Game/textures/player/rock.png");
    
    SDL_Event event;
    while(1)
    {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
    {
            break;
    }
    SDL_RenderClear(win.render);
    const Uint8 *array_addr = SDL_GetKeyboardState(NULL);
    MOVEM_player(&player, array_addr);
    SDL_RenderCopy(win.render, player.texture, NULL, &player.rect);  
    SDL_RenderPresent(win.render);
    }
    return 0;
}

