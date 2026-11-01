#include "dp_game.h"

static int	dp_is_cell_free(t_game *game, int x, int y)
{
    t_entity	*tmp;

    if (game->map.grid[y][x] == '#')
        return 0;
    tmp = game->entities;
    while (tmp != NULL)
    {
        if (tmp->x == x && tmp->y == y)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

static void	dp_monster_move(t_game *game, t_entity *m)
{
    int nx;
    int ny;

    nx = m->x + ((game->player.x > m->x) - (game->player.x < m->x));
    ny = m->y + ((game->player.y > m->y) - (game->player.y < m->y));
    if (nx != m->x && dp_is_cell_free(game, nx, m->y))
        m->x = nx;
    else if (ny != m->y && dp_is_cell_free(game, m->x, ny))
        m->y = ny;
}

static void	dp_monster_act(t_game *game, t_entity *m)
{
    int dist;

    dist = ABS(m->x - game->player.x) + ABS(m->y - game->player.y);
    if (dist <= 5)
    {
        if (dist == 1)
            game->player.hp--;
        else
            dp_monster_move(game, m);
    }
}

void    dp_monsters_play(t_game *game)
{
    t_entity    *tmp;

    if (!game || !game->entities)
        return ;
    tmp = game->entities;
    while (tmp != NULL)
    {
        if (tmp->type == 'M')
            dp_monster_act(game, tmp);
        tmp = tmp->next;
    }
}