/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:21:33 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/18 22:12:56 by jamrabhi         ###   ########.fr       */
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
		_sequence.push_back(atoi(num.c_str()));
	}
	merge_insert();
}

void	recursort(std::vector<std::pair<int, int> > sequence)
{
	
}

void	PmergeMe::merge_insert()
{
	std::cout << "Original sequence :" << std::endl;
	for (size_t i = 0; i < _sequence.size(); ++i)
		std::cout << _sequence[i] << " ";
	std::cout << std::endl;
	
	std::vector<std::pair<int, int> > vec_seq;
	for (size_t i = 1; i < _sequence.size(); i += 2)
	{
		vec_seq.push_back(std::make_pair(_sequence[i-1], _sequence[i]));
	}
	if (_sequence.size() % 2 == 1)
		vec_seq.push_back(std::make_pair(0, _sequence[_sequence.size() - 1]));
		
	std::cout << "Vector with pairs :" << std::endl;
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		std::cout << vec_seq[i].first << " " << vec_seq[i].second << std::endl;
	}
	
	std::cout << "Sorting pairs :" << std::endl;
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		if (vec_seq[i].first < vec_seq[i].second)
			std::swap(vec_seq[i].first, vec_seq[i].second);
	}
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		std::cout << vec_seq[i].first << " " << vec_seq[i].second << std::endl;
	}
	
	
}


