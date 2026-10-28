#ifndef FT_DEPTHS_DP_GAME_H
#define FT_DEPTHS_DP_GAME_H
#include "dp_map.h"

typedef struct s_player
{
    int	x;
    int	y;
    int	hp;
    int	gold;
}	t_player;

typedef struct s_game
{
    t_map			map;
    t_player		player;
    struct s_entity	*entities;
    int				turn;
}	t_game;

int		dp_game_init(t_game *game, const char *map_path);
int		dp_player_move(t_game *game, int dx, int dy);
void	dp_game_render(const t_game *game);
int		dp_game_loop(t_game *game);

#endif