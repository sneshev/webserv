NAME = webserv

FLAGS = -Wall -Wextra -Werror -g -MMD -MP

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.cpp=obj/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

obj/%.o: src/%.cpp | obj
	c++ $(FLAGS) -Iinc/config -Iinc/http -Iinc/networking -c $< -o $@

obj:
	@mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re