#define _POSIX_C_SOURCE 199309
#include "dp_term.h"
#include "dp_utils.h"
#include <signal.h>

volatile sig_atomic_t running = 1;

static void cleanup_handler(int sig) {
    (void)sig;
    running = 0;
}

int main(void) {
    struct termios      saved_term;
    t_key               key;
    struct sigaction    sa;

    sa.sa_handler = cleanup_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    // Enable raw mode at startup
    if (dp_term_raw_on(&saved_term) == -1)
    {
        ft_putstr("Erreur : l'entrée standard n'est pas un terminal.\n");
        return (1);
    }

    running = 1;
    while (running)
    {
        // Read a keypress in a blocking manner
        key = dp_read_key();

        // Process the key
        if (key == KEY_QUIT)
            running = 0;
        else if (key == KEY_UP)
            ft_putstr("KEY_UP\n");
        else if (key == KEY_DOWN)
            ft_putstr("KEY_DOWN\n");
        else if (key == KEY_RIGHT)
            ft_putstr("KEY_RIGHT\n");
        else if (key == KEY_LEFT)
            ft_putstr("KEY_LEFT\n");
        else if (key == KEY_WAIT)
            ft_putstr("KEY_WAIT\n");
        else if (key == KEY_SAVE)
            ft_putstr("KEY_SAVE\n");
        else if (key == KEY_NONE)
            ft_putstr("KEY_NONE\n");
    }

    // ALWAYS restore the terminal before exiting properly
    dp_term_raw_off(&saved_term);
    return (0);
}
