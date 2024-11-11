NAME		= animal
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS		= main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS		= $(SRCS:.cpp=.o)

# Detect operating system
UNAME_S := $(shell uname -s)

# Default target
all:		$(NAME)

# Linking
$(NAME):	$(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[32mCompilation completed successfully!\033[0m"

# Compilation
%.o:		%.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
		@$(RM) $(OBJS)
		@echo "\033[33mObject files removed!\033[0m"

# Clean object files and program
fclean:		clean
		@$(RM) $(NAME)
		@echo "\033[33mProgram removed!\033[0m"

# Check for memory leaks
leaks: all
ifeq ($(UNAME_S),Linux)
		@echo "\033[34mChecking memory leaks with Valgrind...\033[0m"
		@valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
else ifeq ($(UNAME_S),Darwin)
		@echo "\033[34mChecking memory leaks with leaks command...\033[0m"
		@leaks -atExit -- ./$(NAME)
else
		@echo "\033[31mUnsupported operating system for leak checking.\033[0m"
endif

# Rebuild
re:			fclean all

.PHONY:		all clean fclean re leaks