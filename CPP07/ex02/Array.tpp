#include "Array.hpp"

// CANONICAL FORM

template <typename T>
Array<T>::Array()
{
	_array = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array& src)
{
	this->_array = new T[src._size];
	for (size_t i = 0; i < src._size ; i++)
	{
		this->_array[i] = src._array[i];
	}
	this->_size = src._size;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		this->_size = copy._size;
		delete[] this->_array;
		this->_array = new T[copy._size];
		for (size_t i = 0; i < copy._size ; i++)
		{
			this->_array[i] = copy._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}


// ADDITIONNAL

template<typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= size())
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template<typename T>
const T &Array<T>::operator[](size_t index) const
{
	if (index >= size())
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template<typename T>
size_t Array<T>::size() const
{
	return(this->_size);
}