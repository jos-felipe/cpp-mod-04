NAME = interface
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I $(HEADER_PATH)

SRC_PATH = ./src
HEADER_PATH = ./include

SRC = $(wildcard $(SRC_PATH)/*.cpp)
OBJ = $(SRC:.cpp=.o)
HEADER = $(wildcard $(HEADER_PATH)/*.hpp)

VALGRIND	= valgrind
VFLAGS		= --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(SRC_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

leaks: 		re
			$(VALGRIND) $(VFLAGS) ./$(NAME)

.PHONY: all clean fclean re run leaks
