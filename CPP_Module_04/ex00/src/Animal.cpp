/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:22:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/26 20:58:12 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Animal::Animal()
{
	std::cout << "Animal class has been created" << std::endl;
}

Animal::Animal(Animal const &src)
{
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal class has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Animal	&Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "*ANIMAL SOUND*" << std::endl;
}
