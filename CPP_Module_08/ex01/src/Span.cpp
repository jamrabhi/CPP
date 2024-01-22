/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:58:04 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/22 21:43:57 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	Span::addNumber(int n)
{
	if (_data.size() >= _n)
		throw std::length_error("Container is full");

	_data.push_back(n);
}

void	Span::addNumbers(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end)
{
	if (_data.size() >= _n || (it_end - it_begin) >= _n)
		throw std::length_error("Cannot add range of iterators, container is full");
	
	_data.insert(_data.end(), it_begin, it_end);
}

int		Span::shortestSpan()
{
	if (_data.size() <= 1)
		throw std::length_error("Container must have at least 2 numbers stored");
	
	std::sort(_data.begin(), _data.end());
	
	int	shortest = _data[1] - _data[0];
	for (std::vector<int>::iterator it = _data.begin(); (it + 1) != _data.end(); ++it)
	{
		if ((*(it + 1) - *it) < shortest)
			shortest = *(it + 1) - *it;
	}
	return (shortest);
}

int		Span::longestSpan()
{
	if (_data.size() <= 1)
		throw std::length_error("Container must have at least 2 numbers stored");
	std::sort(_data.begin(), _data.end());
	return (*(_data.end() - 1) - *_data.begin());
}
