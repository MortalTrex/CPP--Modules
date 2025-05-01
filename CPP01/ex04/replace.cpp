#include "replace.hpp"

void ft_replace(std::string filename, std::string s1, std::string s2)
{
	std::string line;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
    	std::cerr << "Error: cannot open " << filename << std::endl;
		return ;
	}

	while(std::getline(file, line))
	{
		std::cout << line << std::endl;
		std::cout << s1 << std::endl;
		std::cout << s2 << std::endl;
	}
}