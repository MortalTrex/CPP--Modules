NAME = AMateria

FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp\
	src/Animal.cpp\
	src/Cat.cpp\
	src/Dog.cpp\
	src/Brain.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re