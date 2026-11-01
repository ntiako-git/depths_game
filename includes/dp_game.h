#ifndef FT_DEPTHS_DP_GAME_H
#define FT_DEPTHS_DP_GAME_H
#include "dp_map.h"
#include "dp_term.h"
#include "dp_entity.h"

#define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

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

typedef int	(*t_action)(t_game *game);

typedef struct s_binding
{
    t_key		key;
    t_action	handler;
}	t_binding;

int		dp_game_init(t_game *game, const char *map_path);
void	dp_game_render(const t_game *game);
int		dp_game_loop(t_game *game);
int     dp_act_up(t_game *game);
int     dp_act_down(t_game *game);
int     dp_act_left(t_game *game);
int     dp_act_right(t_game *game);
int     dp_act_wait(t_game *game);
int     dp_dispatch(t_game *game, t_key key);
void	dp_monsters_play(t_game *game);
int     dp_handle_entity(t_game *game, t_entity *entity, int new_x, int new_y);

#endif