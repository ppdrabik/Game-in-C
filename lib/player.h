#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_keyboard.h>
#include <animation.h>

typedef struct
{
    SDL_Rect position;
    Animation_t animate;
    const Uint8 *keys_array;
}Player_s;

void PLAYER_Ctor(Player_s *player, int x, int y, int w, int h);
void PLAYER_Set_Position(Player_s *player, int x, int y);
void PLAYER_Set_Size(Player_s *player, int w, int h);

void PLAYER_Move(Player_s *player);

#endif /* PLAYER_H */