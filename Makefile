NAME = push_swap

SRCS = \

OBJS = $(patsubst %.c, %.o, $(SRCS))
DEPS = $(patsubst %.c, %.d, $(SRCS))

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += -MMD -MP

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CC) $^ -o $@ -c

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)
