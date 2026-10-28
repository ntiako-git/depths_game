#include <termios.h>
#include <unistd.h>
#include "dp_game.h"
#include "dp_term.h"

int main(int argc, char **argv)
{
    t_game          game;
    struct termios	saved_term;

    if (argc != 2)
    {
        write(2, "Error: Invalid arguments.\nUsage: ./ft_depths <map_path>\n", 57);
        return 1;
    }
    if (dp_term_raw_on(&saved_term) == -1)
    {
        write(2, "Error: Not a terminal.\n", 23);
        return 1;
    }
    if (dp_game_init(&game, argv[1]) == -1)
    {
        dp_term_raw_off(&saved_term);
        write(2, "Error: Failed to initialize game or invalid map.\n", 50);
        return 1;
    }
    dp_game_loop(&game);
    dp_map_free(&game.map);
    dp_term_raw_off(&saved_term);
    return 0;
}
