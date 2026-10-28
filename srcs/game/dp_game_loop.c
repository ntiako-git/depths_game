#include "dp_game.h"
#include "dp_term.h"

int	dp_game_loop(t_game *game)
{
    t_key	key;
    int		dx;
    int		dy;

    dp_game_render(game);
    while (1)
    {
        key = dp_read_key();
        if (key == KEY_QUIT)
            break ;
        dx = 0;
        dy = 0;
        if (key == KEY_UP)
            dy = -1;
        else if (key == KEY_DOWN)
            dy = 1;
        else if (key == KEY_LEFT)
            dx = -1;
        else if (key == KEY_RIGHT)
            dx = 1;
        if ((dx != 0 || dy != 0) && dp_player_move(game, dx, dy))
        {
            dp_game_render(game);
            if (game->map.grid[game->player.y][game->player.x] == '>')
                break ;
        }
    }
    return (0);
}
