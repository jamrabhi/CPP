/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:29:36 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/16 20:01:32 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer::~Serializer()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Serializer	&Serializer::operator=(Serializer const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	cast = reinterpret_cast<uintptr_t>(ptr);

	return (cast);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data	*origin = reinterpret_cast<Data*>(raw);

	return (origin);
}
