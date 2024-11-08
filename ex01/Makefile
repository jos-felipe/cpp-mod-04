NAME		= animal
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRCS		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS		= $(SRCS:.cpp=.o)

VALGRIND	= valgrind
VFLAGS		= --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

leaks:		all
			$(VALGRIND) $(VFLAGS) ./$(NAME)

%.o:		%.cpp
			$(CC) $(FLAGS) -c $< -o $@

.PHONY:		all clean fclean re leaks