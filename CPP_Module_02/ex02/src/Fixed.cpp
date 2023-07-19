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
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int fixedValue) : _fixedValue(fixedValue << _fractBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixedValue) : _fixedValue(roundf(fixedValue * (1 << _fractBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Fixed			&Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedValue = rhs._fixedValue;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

bool			Fixed::operator>(Fixed const &rhs) const
{
	if (_fixedValue > rhs._fixedValue)
		return (true);
	return (false);
}

bool			Fixed::operator<(Fixed const &rhs) const
{
	if (_fixedValue < rhs._fixedValue)
		return (true);
	return (false);
}

bool			Fixed::operator>=(Fixed const &rhs) const
{
	if (_fixedValue >= rhs._fixedValue)
		return (true);
	return (false);
}

bool			Fixed::operator<=(Fixed const &rhs) const
{
	if (_fixedValue <= rhs._fixedValue)
		return (true);
	return (false);
}

bool			Fixed::operator==(Fixed const &rhs) const
{
	if (_fixedValue == rhs._fixedValue)
		return (true);
	return (false);
}

bool			Fixed::operator!=(Fixed const &rhs) const
{
	if (_fixedValue != rhs._fixedValue)
		return (true);
	return (false);
}

Fixed			Fixed::operator+(Fixed const &rhs) const
{
	Fixed	rt(toFloat() + rhs.toFloat());

	return (rt);
}

Fixed			Fixed::operator-(Fixed const &rhs) const
{
	Fixed	rt(toFloat() - rhs.toFloat());

	return (rt);
}

Fixed			Fixed::operator*(Fixed const &rhs) const
{
	Fixed	rt(toFloat() * rhs.toFloat());

	return (rt);
}

Fixed			Fixed::operator/(Fixed const &rhs) const
{
	if (rhs.toFloat() == 0)
	{
		std::cout << "Cannot divide by zero, operation aborted" << std::endl;
		return (toFloat());
	}
	Fixed	rt(toFloat() / rhs.toFloat());

	return (rt);
}

Fixed			&Fixed::operator++(void)
{
	_fixedValue++;
	return (*this);
}

Fixed			&Fixed::operator--(void)
{
	_fixedValue--;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed	rt = *this;

	++*this;
	return (rt);
}

Fixed			Fixed::operator--(int)
{
	Fixed	rt = *this;

	--*this;
	return (rt);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

int			Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fixedValue);
}

void		Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_fixedValue = raw;
}

float		Fixed::toFloat() const
{
	return ((float)_fixedValue / (1 << _fractBits));
}

int			Fixed::toInt() const
{
	return (_fixedValue >> _fractBits);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return (a);
	return (b);
}
