/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:23:02 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 01:14:54 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Dog::Dog() : Animal()
{
	type = "Dog";
	_brain = new Brain();
	std::cout << getType() << " class has been created" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	type = src.type;
	_brain = new Brain(*src._brain);
	std::cout << getType() << " copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	delete _brain;
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
		delete _brain;
		_brain = new Brain(*rhs._brain);
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

void	Dog::setIdea(std::string idea)
{
	_brain->ideas[0] = idea;
}

std::string	Dog::getIdea() const
{
	return (_brain->ideas[0]);
}
