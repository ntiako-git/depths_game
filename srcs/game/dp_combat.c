#include "dp_game.h"
#include "dp_entity.h"

static int  dp_random(int max, int seed)
{
    unsigned long long  l_seed;

    l_seed = seed + 42;
    l_seed = l_seed * 1103515245ULL + 12345ULL;
    return l_seed % max;
}

int	dp_handle_entity(t_game *game, t_entity *entity, int new_x, int new_y)
{
    int x;
    int y;

    if (entity->type == '$')
        game->player.gold++;
    else if (entity->type == '!')
        game->player.hp = game->player.hp + 5 > 20 ? 20 : game->player.hp + 5;
    else if (entity->type == 'M')
    {
        entity->hp--;
        if (entity->hp <= 0)
        {
            x = entity->x;
            y = entity->y;
            dp_entity_remove_at(&game->entities, x, y);
            if (dp_random(100, game->player.x + game->player.y) < 50)
                dp_entity_push_back(&game->entities, dp_entity_new('$', x, y));
        }
        return 1;
    }
    game->player.x = new_x;
    game->player.y = new_y;
    dp_entity_remove_at(&game->entities, new_x, new_y);
    return 1;
}