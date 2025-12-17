NAME = push_swap
NAME_bonus = checker

CC = cc
SRCS = \
	compute_disorder.c	\
	main_test.c			\
	ft_bucket.c			\
	ft_flag.c			\
	ft_free_exit.c		\
	ft_init.c			\
	ft_print.c			\
	ft_processe.c		\
	ft_push.c			\
	ft_put_type.c		\
	ft_radix.c			\
	ft_reverse_rotate.c	\
	ft_rotate.c			\
	ft_seletion.c		\
	ft_split_stack.c	\
	ft_swap.c			\
	push_swap.c			\

SRCS_BONUS= \
	checker.c			\
	main_test.c			\
	get_next_line.c		\
	compute_disorder.c	\
	ft_bucket.c			\
	ft_flag.c			\
	ft_free_exit.c		\
	ft_init.c			\
	ft_print.c			\
	ft_processe.c		\
	ft_push.c			\
	ft_put_type.c		\
	ft_radix.c			\
	ft_reverse_rotate.c	\
	ft_rotate.c			\
	ft_seletion.c		\
	ft_split_stack.c	\
	ft_swap.c			\

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_bonus= $(patsubst %.c, %.o, $(SRCS_BONUS))

DEPS = $(patsubst %.c, %.d, $(SRCS))
DEPS_bonus = $(patsubst %.c, %.d, $(SRCS_BONUS))

CFLAGS += -Werror -Wextra -Wall -MMD -MP

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(OBJS) -o $@

bonus: $(NAME_bonus)

$(NAME_bonus): $(OBJS_bonus)
	$(CC) $(OBJS_bonus) -o $@

clean:
	rm -f $(OBJS) $(DEPS) $(OBJS_bonus) $(DEPS_bonus)

fclean: clean
	rm -f $(NAME) $(NAME_bonus)

re: fclean all

-include $(DEPS) $(DEPS_bonus)

.PHONY: all clean fclean re