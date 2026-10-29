#ifndef FT_DEPTHS_DP_ENTITY_H
#define FT_DEPTHS_DP_ENTITY_H
#include "dp_game.h"
#include <stdlib.h>

typedef struct s_entity
{
    char			type;	/* 'M', '$', '!' */
    int				x;
    int				y;
    int				hp;
    struct s_entity	*next;
}	t_entity;

t_entity	*dp_entity_new(char type, int x, int y);
void		dp_entity_push_back(t_entity **list, t_entity *new);
t_entity	*dp_entity_at(t_entity *list, int x, int y);
void		dp_entity_remove_at(t_entity **list, int x, int y);
void		dp_entity_clear(t_entity **list);
int			dp_entity_spawn_all(t_game *game);

#endif