#include "Fixed.hpp"

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	std::cout << "\033[31mSubject test : increment and decrements operators\033[0m" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "\033[34ma : \033[0m" << a << std::endl;
	std::cout << "\033[34m++a : \033[0m" << ++a << std::endl;
	std::cout << "\033[34ma : \033[0m" << a << std::endl;
	std::cout << "\033[34ma++ : \033[0m" << a++ << std::endl;
	std::cout << "\033[34ma : \033[0m" << a << std::endl;

	std::cout << "\033[34mb : \033[0m" << b << std::endl;

	std::cout << "\033[34mmax between a and b : \033[0m" << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	
	std::cout << "\033[32mMORE TESTS\033[0m" << std::endl;
	a = b;
	std::cout << "\033[34ma after a = b : \033[0m" << a << std::endl;
	std::cout << "\033[34m--a : \033[0m" << --a << std::endl;
	std::cout << "\033[34ma : \033[0m" << a << std::endl;
	std::cout << "\033[34ma-- : \033[0m" << a-- << std::endl;
	std::cout << "\033[34ma : \033[0m" << a << std::endl;
	std::cout << "\033[34mmin betweem a and b: \033[0m" << Fixed::min( a, b ) << std::endl;
	Fixed c(42.42f);
	Fixed d(42.42f);

	std::cout << "\033[34mc is \033[0m" << c << std::endl;
	std::cout << "\033[34md is \033[0m" << d << std::endl;
	std::cout << std::endl;
	std::cout << "\033[32mComparison operators\033[0m" << std::endl;
	std::cout << "\033[34mc > d ? \033[0m" << (c > d) << std::endl;
	std::cout << "\033[34mc < d ? \033[0m" << (c < d) << std::endl;
	std::cout << "\033[34mc >= d ? \033[0m" << (c >= d) << std::endl;
	std::cout << "\033[34mc <= d ? \033[0m" << (c <= d) << std::endl;
	std::cout << "\033[34mc == d ? \033[0m" << (c == d) << std::endl;
	std::cout << "\033[34mc != d ? \033[0m" << (c != d) << std::endl;
	std::cout << std::endl;
	std::cout << "\033[32mArithmetic operators\033[0m" << std::endl;

	std::cout << "\033[34mc + d = \033[0m" << c + d << std::endl;
	std::cout << "\033[34mc - d = \033[0m" << c - d << std::endl;
	std::cout << "\033[34mc * d = \033[0m" << c * d << std::endl;
	std::cout << "\033[34mc / d = \033[0m" << c / d << std::endl;

	return 0;
}