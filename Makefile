NAME        = ft_depths
CFLAGS      = -Wall -Wextra -Werror -std=c99 -pedantic -g
INCLUDES    = -I includes
UTILS_SRCS  = srcs/utils/ft_strlen.c \
              srcs/utils/ft_putstr.c \
              srcs/utils/ft_putnbr.c \
              srcs/utils/ft_strdup.c \
              srcs/utils/ft_strcmp.c
MAP_SRCS    = srcs/map/dp_map_load.c \
              srcs/map/dp_map_check.c \
              srcs/map/dp_map_render.c \
              srcs/map/dp_map_free.c
TERM_SRCS	= srcs/term/dp_term.c \
			  srcs/term/dp_key.c
SRCS        = srcs/main.c $(UTILS_SRCS) $(MAP_SRCS) $(TERM_SRCS)
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) test_ex0 test_ex1 test_ex2

fclean: clean
	rm -f $(NAME)

re: fclean all

test: test_ex0 test_ex1 test_ex2
	@echo "\n=== Executing test_ex0 ==="
	@./test_ex0
	@echo "\n=== Executing de test_ex1 ==="
	@./test_ex1
	@echo "\n=== Executing de test_ex2 ==="
	@./test_ex2

test_ex0: tests/test_ex0.c $(UTILS_SRCS)
	cc $(CFLAGS) $(INCLUDES) tests/test_ex0.c $(UTILS_SRCS) -o test_ex0

test_ex1: tests/test_ex1.c $(UTILS_SRCS) $(MAP_SRCS)
	cc $(CFLAGS) $(INCLUDES) tests/test_ex1.c $(UTILS_SRCS) $(MAP_SRCS) -o test_ex1

test_ex2: tests/test_ex2.c $(UTILS_SRCS)
	cc $(CFLAGS) $(INCLUDES) tests/test_ex2.c $(UTILS_SRCS) $(TERM_SRCS) -o test_ex2

.PHONY: all clean fclean re test test_ex0 test_ex1 test_ex2