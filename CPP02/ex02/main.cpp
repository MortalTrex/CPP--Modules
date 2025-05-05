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
	std::cout << "\033[34mmax : \033[0m" << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << "\033[32mTests Additionnels\033[0m" << std::endl;
	std::cout << "\033[34m--a : \033[0m" << --a << std::endl;
	std::cout << "\033[34ma : \033[0m" << a << std::endl;
	std::cout << "\033[34ma-- : \033[0m" << a-- << std::endl;
	std::cout << "\033[34ma : \033[0m" << a << std::endl;
	std::cout << "\033[34mmin : \033[0m" << Fixed::min( a, b ) << std::endl;
	Fixed c(42.42f);
	Fixed d(42.42f);

	std::cout << "\033[34mc is \033[0m" << c << std::endl;
	std::cout << "\033[34md is \033[0m" << d << std::endl;
	std::cout << std::endl;
	std::cout << "\033[32mOPERATEURS DE COMPARAISON\033[0m" << std::endl;
	std::cout << "\033[34mc > d ? \033[0m" << (c > d) << std::endl;
	std::cout << "\033[34mc < d ? \033[0m" << (c < d) << std::endl;
	std::cout << "\033[34mc >= d ? \033[0m" << (c >= d) << std::endl;
	std::cout << "\033[34mc <= d ? \033[0m" << (c <= d) << std::endl;
	std::cout << "\033[34mc == d ? \033[0m" << (c == d) << std::endl;
	std::cout << "\033[34mc != d ? \033[0m" << (c != d) << std::endl;
	std::cout << std::endl;
	std::cout << "\033[32mOPERATEURS ARITHMETIQUE\033[0m" << std::endl;
	Fixed add = c + d;
	Fixed sub = c - d;
	Fixed mul = c * d;
	Fixed div = c / d;

	std::cout << "\033[34mc + d = \033[0m" << add << std::endl;
	std::cout << "\033[34mc - d = \033[0m" << sub << std::endl;
	std::cout << "\033[34mc * d = \033[0m" << mul << std::endl;
	std::cout << "\033[34mc / d = \033[0m" << div << std::endl;



	return 0;
}