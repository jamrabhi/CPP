/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:21:33 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/16 21:35:07 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

PmergeMe::PmergeMe(int ac, char *av[])
{
	parseSequence(ac, av);
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	checkDigit(std::string num)
{
	for (size_t i = 0; i < num.length(); ++i)
	{
		if (!isdigit(num[i]))
			throw std::runtime_error("sequence must contains only positive int");
	}
	if (atoi(num.c_str()) <= 0)
		throw std::runtime_error("sequence must contains only positive int");
}

void	PmergeMe::parseSequence(int ac, char *av[])
{
	std::string	num;
	
	for	(int i = 1; i < ac; ++i)
	{
		num = av[i];
		checkDigit(num);
		_vec_seq.push_back(atoi(num.c_str()));
	}
	merge_insert();
}

void	PmergeMe::merge_insert()
{
	for (size_t i = 0; i <= (_vec_seq.size() / 2); ++i)
	{
		
	}
}


