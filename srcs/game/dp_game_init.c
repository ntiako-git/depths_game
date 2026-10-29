#include "dp_game.h"
#include "dp_entity.h"

static int	dp_init_player_pos(t_game *game)
{
    int	y;
    int	x;

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
                return (0);
            }
            x++;
        }
        y++;
    }
    return -1;
}

int		dp_game_init(t_game *game, const char *map_path) {
    if (dp_map_load(map_path, &game->map) != MAP_OK)
        return -1;
    if (dp_map_check(&game->map) != MAP_OK)
    {
        dp_map_free(&game->map);
        return -1;
    }
    if (dp_entity_spawn_all(game) == -1 || dp_init_player_pos(game) == -1)
    {
        dp_entity_clear(&game->entities);
        dp_map_free(&game->map);
        return -1;
    }
    game->player.hp = 10;
    game->player.gold = 0;
    game->turn = 0;
    return 0;
}