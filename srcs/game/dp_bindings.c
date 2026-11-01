#include "dp_game.h"

static const t_binding  g_bindings[] = {
    {.key = KEY_UP, .handler = dp_act_up},
    {.key = KEY_DOWN, .handler = dp_act_down},
    {.key = KEY_LEFT, .handler = dp_act_left},
    {.key = KEY_RIGHT, .handler = dp_act_right},
    {.key = KEY_WAIT, .handler = dp_act_wait},
    {.key = KEY_NONE, .handler = NULL},
};

int     dp_dispatch(t_game *game, t_key key)
{
    int i;

    i = 0;
    while (g_bindings[i].key != KEY_NONE)
    {
        if (g_bindings[i].key == key)
            return g_bindings[i].handler(game);
        i++;
    }
    return 0;
}