NAME = push_swap
CC = cc
SRCS = \

OBJS = $(patsubst %.c, %.o, $(SRCS))
DEPS = $(patsubst %.c, %.d, $(SRCS))

CFLAGS += -Werror -Wextra -Wall -MMD -MP

all: $(NAME) 

$(NAME): $(OBJS) $(DEPS) Makefile
	$(CC) $^ -o $@ -c

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re