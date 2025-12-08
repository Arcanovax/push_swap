NAME = push_swap
SRCS = 		\

OBJS = $(patsubst %.c, %.o, $(SRCS))
DEPS = $(patsubst %.c, %.d, $(SRCS))

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += -MMD -MP

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES)

clean:
	rm -fv $(OBJS) $(DEPS)

fclean: clean
	rm -fv $(NAME)

re: fclean all

-include $(DEPS)
