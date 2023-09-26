/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:22:30 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/26 23:01:16 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << getType() << " class has been created" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	type = src.type;
	std::cout << getType() << " copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << getType() << " class has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	Cat::makeSound() const
{
	std::cout << "*MIAOU MIAOU*" << std::endl;
}

