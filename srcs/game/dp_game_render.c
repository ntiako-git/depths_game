#include "dp_game.h"
#include "dp_utils.h"
#include "dp_entity.h"

static void dp_render_grid(const t_game *game)
{
    int         y;
    int         x;
    t_entity    *entity;

    y = 0;
    while (y < game->map.h)
    {
        x = 0;
        while (x < game->map.w)
        {
            if (x == game->player.x && y == game->player.y)
                write(1, "@", 1);
            else if (dp_entity_at(game->entities, x, y) != NULL)
            {
                entity = dp_entity_at(game->entities, x, y);
                write(1, &entity->type, 1);
            }
            else
                write(1, &game->map.grid[y][x], 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
}

void    dp_game_render(const t_game *game)
{
    ft_putstr("\033[H\033[2J");
    dp_render_grid(game);
    ft_putstr("HP ");
    ft_putnbr(game->player.hp);
    ft_putstr("  Gold ");
    ft_putnbr(game->player.gold);
    ft_putstr("  Turn ");
    ft_putnbr(game->turn);
    ft_putstr("\n");
}