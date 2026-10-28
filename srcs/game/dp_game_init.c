#include "dp_game.h"

int		dp_game_init(t_game *game, const char *map_path)
{
    t_map_err   err;
    int         x;
    int         y;

    err = dp_map_load(map_path, &game->map);
    if (err != MAP_OK)
        return -1;
    err = dp_map_check(&game->map);
    if (err != MAP_OK)
        return -1;
    y = 0;
    while (y < game->map.h)
    {
        x = 0;
        while (x < game->map.w)
        {
            if (game->map.grid[y][x] == '@')
            {
                game->player.x = x;
                game->player.y = y;
                game->map.grid[y][x] = '.';
            }
            x++;
        }
        y++;
    }
    game->player.hp = 10;
    game->player.gold = 0;
    game->turn = 0;
    return 0;
}