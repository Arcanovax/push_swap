NAME = push_swap
NAME_bonus = checker

CC = cc

SRCS = \
	compute_disorder.c	\
	debug.c			\
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
	ft_bucket_utils.c	\

SRCS_BONUS= \
	checker.c			\
	debug.c				\
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
	ft_bucket_utils.c	\


OBJDIR = .obj

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
OBJS_bonus = $(SRCS_BONUS:%.c=$(OBJDIR)/%.o)

DEPS = $(OBJS:.o=.d)
DEPS_bonus = $(OBJS_bonus:.o=.d)

CFLAGS += -Werror -Wextra -Wall -MMD -MP

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(OBJS) -o $@

bonus: $(NAME_bonus)

$(NAME_bonus): $(OBJS_bonus)
	$(CC) $(OBJS_bonus) -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS) $(OBJS_bonus) $(DEPS_bonus)

fclean: clean
	rm -f $(NAME) $(NAME_bonus)

re: fclean all

-include $(DEPS) $(DEPS_bonus)

.PHONY: all clean fclean re
