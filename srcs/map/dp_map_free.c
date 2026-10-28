#include "dp_map.h"

void	dp_map_free(t_map *map)
{
    int	y;

    if (!map || !map->grid)
        return ;
    y = 0;
    while (y < map->h && map->grid[y])
    {
        free(map->grid[y]);
        y++;
    }
    free(map->grid);
    map->grid = NULL;
    map->h = 0;
    map->w = 0;
}