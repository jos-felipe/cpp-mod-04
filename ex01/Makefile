NAME		= conscious_animals
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS		= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS		= $(SRCS:.cpp=.o)

VALGRIND	= valgrind
VFLAGS		= --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[32mCompilation completed successfully!\033[0m"

%.o:		%.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)
		@echo "\033[33mObject files removed!\033[0m"

fclean:		clean
		@$(RM) $(NAME)
		@echo "\033[33mProgram removed!\033[0m"

re:			fclean all

leaks: 		re
			$(VALGRIND) $(VFLAGS) ./$(NAME)

.PHONY:		all clean fclean re leaks