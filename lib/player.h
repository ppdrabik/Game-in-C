#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_keyboard.h>
typedef struct
{
    SDL_Rect rect;
    SDL_Texture *texture;
    const Uint8 *keys_array;
}Player_s;

void PLAYER_Ctor(Player_s *player, SDL_Texture* texture, int x, int y, int w, int h);
void PLAYER_Set_Position(Player_s *player, int x, int y);
void PLAYER_move(Player_s *player);

#endif /* PLAYER_H */