/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:22:30 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 05:31:21 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Cat::Cat() : AAnimal()
{
	type = "Cat";
	_brain = new Brain();
	std::cout << getType() << " class has been created" << std::endl;
}

Cat::Cat(Cat const &src) : AAnimal(src)
{
	type = src.type;
	_brain = new Brain(*src._brain);
	std::cout << getType() << " copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	delete _brain;
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
		delete _brain;
		_brain = new Brain(*rhs._brain);
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

void	Cat::setIdea(std::string idea)
{
	_brain->ideas[0] = idea;
}


std::string	Cat::getIdea() const
{
	return (_brain->ideas[0]);
}
