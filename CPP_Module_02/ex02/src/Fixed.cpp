/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:26:55 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/12 00:26:58 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Fixed::Fixed() : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int fixedValue) : _fixedValue(fixedValue << _fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixedValue) : _fixedValue(roundf(fixedValue * (1 << _fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Fixed			&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedValue = rhs._fixedValue;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedValue = raw;
}

float	Fixed::toFloat() const
{
	return ((float)_fixedValue / (1 << _fractBits));
}

int		Fixed::toInt() const
{
	return (_fixedValue >> _fractBits);
}
