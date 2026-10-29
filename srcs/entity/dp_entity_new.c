#include "dp_entity.h"

typedef struct s_entity_config
{
    char    type;
    int     hp;
}   t_entity_config;

static const t_entity_config    g_entity_configs[] = {
    {.type = 'M', .hp = 3},
    {.type = '$', .hp = 1},
    {.type = '!', .hp = 1}
};

static int  get_default_hp(char type)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (g_entity_configs[i].type == type)
            return g_entity_configs[i].hp;
        i++;
    }
    return 1;
}

t_entity    *dp_entity_new(char type, int x, int y)
{
    t_entity    *new_entity;

    new_entity = malloc(sizeof(t_entity));
    if (!new_entity)
        return NULL;
    new_entity->type = type;
    new_entity->hp = get_default_hp(type);
    new_entity->x = x;
    new_entity->y = y;
    new_entity->next = NULL;

    return new_entity;
}