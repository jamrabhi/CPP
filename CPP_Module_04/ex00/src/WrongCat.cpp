/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:25:59 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/22 23:27:49 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << getType() << " class has been created" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << getType() << " class has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	WrongCat::makeSound() const
{
	std::cout << "FAKE MIAOU MIAOU" << std::endl;
}

