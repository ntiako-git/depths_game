#include "dp_game.h"
#include "dp_utils.h"

void	dp_game_render(const t_game *game)
{
    int	y;
    int	x;

    ft_putstr("\033[H\033[2J");
    y = 0;
    while (y < game->map.h)
    {
        x = 0;
        while (x < game->map.w)
        {
            if (x == game->player.x && y == game->player.y)
                write(1, "@", 1);
            else
                write(1, &game->map.grid[y][x], 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
    ft_putstr("HP ");
    ft_putnbr(game->player.hp);
    ft_putstr("  Gold ");
    ft_putnbr(game->player.gold);
    ft_putstr("  Turn ");
    ft_putnbr(game->turn);
    ft_putstr("\n");
}