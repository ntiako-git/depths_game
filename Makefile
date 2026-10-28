NAME        = ft_depths
CFLAGS      = -Wall -Wextra -Werror -std=c99 -pedantic -g
INCLUDES    = -I includes
SRCS        = srcs/main.c \
              srcs/utils/ft_strlen.c \
              srcs/utils/ft_putstr.c \
              srcs/utils/ft_putnbr.c \
              srcs/utils/ft_strdup.c \
              srcs/utils/ft_strcmp.c
OBJS        = $(SRCS:.c=.o)
UTILS_SRCS  = srcs/utils/ft_strlen.c \
              srcs/utils/ft_putstr.c \
              srcs/utils/ft_putnbr.c \
              srcs/utils/ft_strdup.c \
              srcs/utils/ft_strcmp.c

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) tests/test_ex0

fclean: clean
	rm -f $(NAME) test_ex0

re: fclean all

test: test_ex0
	@echo "\n=== Execution de test_ex0 ==="
	@./test_ex0

test_ex0: tests/test_ex0.c $(UTILS_SRCS)
	cc $(CFLAGS) $(INCLUDES) tests/test_ex0.c $(UTILS_SRCS) -o test_ex0

.PHONY: all clean fclean re test