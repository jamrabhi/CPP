/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 05:28:13 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 05:38:23 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

AAnimal::AAnimal()
{
	std::cout << "Abstract Animal class has been created" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "Abstract Animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "Abstract Animal class has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

std::string	AAnimal::getType() const
{
	return (type);
}
