#include <player.h>
#include <rectangle.h>

void PLAYER_Ctor(Player_s *player, SDL_Texture* texture, int x, int y, int w, int h)
{
    SDL_Rect_Ctor(&player->rect, x, y, w, h);
    player->texture = texture;
    player->keys_array = SDL_GetKeyboardState(NULL);
}


void PLAYER_Set_Position(Player_s *player, int x, int y)
{
    player->rect.x = x;
    player->rect.y = y;
}


void PLAYER_move(Player_s *player)
{
   if(player->keys_array[SDL_SCANCODE_W] == 1)
   {
      PLAYER_Set_Position(player, player->rect.x, (player->rect.y) -1);
      
   }
   if(player->keys_array[SDL_SCANCODE_S] == 1)
   {
      PLAYER_Set_Position(player, player->rect.x, (player->rect.y) +1);
      
   }
   if(player->keys_array[SDL_SCANCODE_A] == 1)
   {
      PLAYER_Set_Position(player, (player->rect.x) -1, player->rect.y);
      
   }
   if(player->keys_array[SDL_SCANCODE_D] == 1)
   {
      PLAYER_Set_Position(player, (player->rect.x) +1, player->rect.y);
      
   }
}