#include "dp_game.h"

int		dp_player_move(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    new_x = game->player.x + dx;
    new_y = game->player.y + dy;

    if (game->map.grid[new_y][new_x] == '#')
        return 0;
    game->player.x = new_x;
    game->player.y = new_y;
    game->turn++;
    return 1;
}