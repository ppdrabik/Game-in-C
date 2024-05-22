#ifndef MOVEMENT_H
#define MOVEMENT_H


#include <SDL.h>
#include <player.h>
#include <stdio.h>

SDL_Event move_event;
void MOVEM_player(Player_s *player, const uint8_t *array);
#endif /* MOVEMENT */