/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:23:02 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/26 22:59:01 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << getType() << " class has been created" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	type = src.type;
	std::cout << getType() << " copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << getType() << " class has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Dog	&Dog::operator=(Dog const &rhs)
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

void	Dog::makeSound() const
{
	std::cout << "*WOAF WOAF*" << std::endl;
}
