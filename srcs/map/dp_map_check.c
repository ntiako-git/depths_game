#include "dp_map.h"

static t_map_err   dp_char_check(const char c, int *p_count, int *e_count)
{
    if (c != '#' && c != '.' && c != '@' && c != '>' && c != 'M' && c != '$' && c != '!')
        return MAP_ERR_CHAR;
    if (c == '@')
        (*p_count)++;
    if (c == '>')
        (*e_count)++;
    return MAP_OK;
}

static t_map_err	dp_parse_grid(const t_map *map, int *p_count, int *e_count)
{
    int		y;
    int		x;
    char	c;
    t_map_err	err;

    y = 0;
    while (y < map->h)
    {
        x = 0;
        while (x < map->w)
        {
            c = map->grid[y][x];
            if ((y == 0 || y == map->h - 1 || x == 0 || x == map->w - 1)
                && c != '#')
                return MAP_ERR_RULES;
            err = dp_char_check(c, p_count, e_count);
            if (err != MAP_OK)
                return err;
            x++;
        }
        y++;
    }
    return MAP_OK;
}

t_map_err   dp_map_check(const t_map *map)
{
    int			player_count;
    int			exit_count;
    t_map_err	err;

    if (!map || !map->grid || map->w <= 0 || map->h <= 0)
        return MAP_ERR_SHAPE;
    player_count = 0;
    exit_count = 0;
    err = dp_parse_grid(map, &player_count, &exit_count);
    if (err != MAP_OK)
        return err;
    if (player_count != 1 || exit_count != 1)
        return MAP_ERR_RULES;
    return MAP_OK;
}