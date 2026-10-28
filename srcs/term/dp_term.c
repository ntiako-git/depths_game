#include "dp_term.h"

int		dp_term_raw_on(struct termios *saved)
{
    struct termios  raw;

    if (isatty(STDIN_FILENO) == 0)
        return -1;
    tcgetattr(STDIN_FILENO, saved);  /* saves the original state */
    raw = *saved;
    raw.c_lflag &= ~(ICANON | ECHO);    /* no line, no echo */
    raw.c_cc[VMIN] = 1;                 /* read blocks until 1 byte is available */
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    return 0;
}

void	dp_term_raw_off(const struct termios *saved)
{
    tcsetattr(STDIN_FILENO, TCSANOW, saved);
}