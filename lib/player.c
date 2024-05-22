#include <player.h>
#include <rectangle.h>

void PLAYER_Ctor(Player_s *player, SDL_Texture* texture, int x, int y, int w, int h)
{
    SDL_Rect_Ctor(&player->rect, x, y, w, h);
    player->texture = texture;
}


void PLAYER_Set_Position(Player_s *player, int x, int y)
{
    player->rect.x = x;
    player->rect.y = y;
}


