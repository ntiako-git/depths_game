#ifndef FT_DEPTHS_DP_MAP_H
#define FT_DEPTHS_DP_MAP_H
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
    char	**grid;
    int		w;
    int		h;
}	t_map;

typedef enum e_map_err
{
    MAP_OK,
    MAP_ERR_IO,
    MAP_ERR_ALLOC,
    MAP_ERR_SHAPE,
    MAP_ERR_CHAR,
    MAP_ERR_RULES
}	t_map_err;

t_map_err	dp_map_load(const char *path, t_map *map);
t_map_err	dp_map_check(const t_map *map);
void		dp_map_render(const t_map *map);
void		dp_map_free(t_map *map);

#endif
