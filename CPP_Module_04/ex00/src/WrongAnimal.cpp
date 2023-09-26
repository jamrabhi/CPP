/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:59:47 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/26 20:58:03 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong animal class has been created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal class has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if ( this != &rhs )
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

std::string	WrongAnimal::getType() const
{
	return (type);
}

void		WrongAnimal::makeSound() const
{
	std::cout << "*FAKE ANIMAL SOUND*" << std::endl;
}

