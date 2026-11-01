#include "dp_game.h"

static int  dp_player_try_move(t_game *game, int dx, int dy)
{
    int         new_x;
    int         new_y;
    t_entity    *entity;

    new_x = game->player.x + dx;
    new_y = game->player.y + dy;
    if (game->map.grid[new_y][new_x] == '#')
        return 0;
    entity = dp_entity_at(game->entities, new_x, new_y);
    if (entity != NULL)
        return dp_handle_entity(game, entity, new_x, new_y);
    game->player.x = new_x;
    game->player.y = new_y;
    return 1;
}

int     dp_act_up(t_game *game)
{
    return dp_player_try_move(game, 0, -1);
}

int     dp_act_down(t_game *game)
{
    return dp_player_try_move(game, 0, 1);
}

int     dp_act_left(t_game *game)
{
    return dp_player_try_move(game, -1, 0);
}

int     dp_act_right(t_game *game)
{
    return dp_player_try_move(game, 1, 0);
}

int     dp_act_wait(t_game *game)
{
    (void)game;
    return 1;
}