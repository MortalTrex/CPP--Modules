#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
T &Array<T>::operator[]( unsigned int index )
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}
