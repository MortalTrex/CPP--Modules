#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "\033[34mMemory address String:\033[0m " << &str << std::endl;
	std::cout << "\033[34mMemory address Pointer:\033[0m " << stringPTR << std::endl;
	std::cout << "\033[34mMemory address Reference:\033[0m " << &stringREF << std::endl;

	std::cout << "\033[36mValue String:\033[0m " << str << std::endl;
	std::cout << "\033[36mValue Pointer:\033[0m " << *stringPTR << std::endl;
	std::cout << "\033[36mValue Reference:\033[0m " << stringREF << std::endl;
	return 0;
}