/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:44:23 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/24 01:38:30 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : _size(0), _data(NULL)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n <= 0)
		throw IndexException();
	_data = new T[n]();
}

template<typename T>
Array<T>::Array(Array<T> const &src)
{
	_size = src.size();
	_data = new T[size()]();
	for (unsigned int i = 0; i < size(); i++)
		_data[i] = src._data[i];
}

template<typename T>
Array<T>::~Array()
{
	if (_data)
		delete [] _data;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

template<typename T>
Array<T>	&Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		_size = rhs.size();
		if (_data)
			delete [] _data;
		_data = new T[size()]();
		for (unsigned int i = 0; i < size(); i++)
			_data[i] = rhs._data[i];
	}
	return (*this);
}

template<typename T>
T			&Array<T>::operator[](unsigned int index) const
{
	if (index >= size())
		throw IndexException();
	return (_data[index]);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

template<typename T>
const char*	Array<T>::IndexException::what() const throw()
{
	return ("Index is out of bonds");
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

