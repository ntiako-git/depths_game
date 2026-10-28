#ifndef FT_DEPTHS_DP_TERM_H
#define FT_DEPTHS_DP_TERM_H
#include <termios.h>
#include <unistd.h>

typedef enum e_key
{
    KEY_NONE,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_QUIT,
    KEY_SAVE,
    KEY_WAIT
}	t_key;

int		dp_term_raw_on(struct termios *saved);
void	dp_term_raw_off(const struct termios *saved);
t_key	dp_read_key(void);

#endif