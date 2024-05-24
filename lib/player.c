#include <player.h>
#include <rectangle.h>

void PLAYER_Ctor(Player_s *player, int x, int y, int w, int h)
{
    SDL_Rect_Ctor(&player->position, x, y, w, h);
    player->keys_array = SDL_GetKeyboardState(NULL);
}


void PLAYER_Set_Position(Player_s *player, int x, int y)
{
    player->position.x = x;
    player->position.y = y;
}

void PLAYER_Set_Size(Player_s *player, int w, int h)
{
    player->position.w = w;
    player->position.h = h;
}


void PLAYER_Move(Player_s *player)
{
   if(player->keys_array[SDL_SCANCODE_W] == 1)
   {
      PLAYER_Set_Position(player, player->position.x, (player->position.y) -1);
      
   }
   if(player->keys_array[SDL_SCANCODE_S] == 1)
   {
      PLAYER_Set_Position(player, player->position.x, (player->position.y) +1);
      
   }
   if(player->keys_array[SDL_SCANCODE_A] == 1)
   {
      PLAYER_Set_Position(player, (player->position.x) -1, player->position.y);
      
   }
   if(player->keys_array[SDL_SCANCODE_D] == 1)
   {
      PLAYER_Set_Position(player, (player->position.x) +1, player->position.y);
      
   }
}