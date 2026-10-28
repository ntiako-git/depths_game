#include "dp_map.h"
#include "dp_utils.h"

void		dp_map_render(const t_map *map)
{
    int	y;

    if (!map || !map->grid)
        return ;
    y = 0;
    while (y < map->h)
    {
        ft_putstr(map->grid[y]);
        write(1, "\n", 1);
        y++;
    }
}
