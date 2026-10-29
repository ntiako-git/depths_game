#include "dp_entity.h"

int dp_entity_spawn_all(t_game *game)
{
    int         y;
    int         x;
    char        c;
    t_entity    *new_entity;

    game->entities = NULL;
    y = 0;
    while (y < game->map.h)
    {
        x = 0;
        while (x < game->map.w)
        {
            c = game->map.grid[y][x];
            if (c == 'M' || c == '$' || c == '!')
            {
                new_entity = dp_entity_new(c, x, y);
                if (!new_entity)
                {
                    dp_entity_clear(&game->entities);
                    return -1;
                }
                dp_entity_push_back(&game->entities, new_entity);
                game->map.grid[y][x] = '.';
            }
            x++;
        }
        y++;
    }
    return 0;
}