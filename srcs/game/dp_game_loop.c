#include "dp_game.h"
#include "dp_utils.h"

int	dp_game_loop(t_game *game)
{
    t_key	key;

    dp_game_render(game);
    while (1)
    {
        key = dp_read_key();
        if (key == KEY_QUIT)
            break ;
        if (dp_dispatch(game, key) == 1)
        {
            dp_monsters_play(game);
            game->turn++;
            if (game->player.hp <= 0)
            {
                ft_putstr("You died on turn ");
                ft_putnbr(game->turn - 1);
                ft_putstr(".\n");
                break ;
            }
            dp_game_render(game);
            if (game->map.grid[game->player.y][game->player.x] == '>')
                break ;
        }
    }
    return 0;
}
