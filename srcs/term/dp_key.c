#include "dp_term.h"

static t_key	dp_read_escape_sequence(void)
{
    char	c;

    if (read(STDIN_FILENO, &c, 1) < 0 || c != '[')
        return (KEY_NONE);
    if (read(STDIN_FILENO, &c, 1) < 0)
        return (KEY_NONE);
    if (c == 'A')
        return (KEY_UP);
    if (c == 'B')
        return (KEY_DOWN);
    if (c == 'C')
        return (KEY_RIGHT);
    if (c == 'D')
        return (KEY_LEFT);
    return (KEY_NONE);
}

static t_key	dp_map_char_to_key(char c)
{
    if (c == 'z' || c == 'Z')
        return (KEY_UP);
    if (c == 's' || c == 'S')
        return (KEY_DOWN);
    if (c == 'q' || c == 'Q')
        return (KEY_LEFT);
    if (c == 'd' || c == 'D')
        return (KEY_RIGHT);
    if (c == 'a' || c == 'A')
        return (KEY_QUIT);
    if (c == 'p' || c == 'P')
        return (KEY_SAVE);
    if (c == ' ')
        return (KEY_WAIT);
    return (KEY_NONE);
}

t_key	dp_read_key(void)
{
    char	c;

    if (read(STDIN_FILENO, &c, 1) <= 0)
        return (KEY_NONE);
    if (c == 27)
        return (dp_read_escape_sequence());
    return (dp_map_char_to_key(c));
}
