NAME = Bureaucrat

FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp\
	src/Bureaucrat.cpp\
	src/PresidentialPardonForm.cpp\
	src/RobotomyRequestForm.cpp\
	src/ShrubberyCreationForm.cpp

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