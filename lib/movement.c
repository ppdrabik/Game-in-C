#include <movement.h>


void MOVEM_player(Player_s *player, const uint8_t *array)
{
   if(array[SDL_SCANCODE_W] == 1)
   {
      PLAYER_Set_Position(player, player->rect.x, (player->rect.y) -1);
      
   }
   if(array[SDL_SCANCODE_S] == 1)
   {
      PLAYER_Set_Position(player, player->rect.x, (player->rect.y) +1);
      
   }
   if(array[SDL_SCANCODE_A] == 1)
   {
      PLAYER_Set_Position(player, (player->rect.x) -1, player->rect.y);
      
   }
   if(array[SDL_SCANCODE_D] == 1)
   {
      PLAYER_Set_Position(player, (player->rect.x) +1, player->rect.y);
      
   }
}
