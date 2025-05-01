#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error : Bad arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	ft_replace(argv[1], argv[2], argv[3]);
	return (EXIT_SUCCESS);
}