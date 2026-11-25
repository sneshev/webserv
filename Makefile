NAME = webserv

FLAGS = -Wall -Wextra -Werror -g -MMD -MP

SRCS =	$(wildcard src/*.cpp) \
		$(wildcard src/http/*.cpp) \
		$(wildcard src/utils/*.cpp)

OBJS = $(patsubst src/%.cpp,obj/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)


all: $(NAME)


$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	c++ $(FLAGS) -MMD -MP -I inc -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re