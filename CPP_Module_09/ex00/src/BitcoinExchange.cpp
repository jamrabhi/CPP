/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:34:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/08 21:53:33 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(std::string database, std::string fileInput) :
	_database(database.c_str()), _fileInput(fileInput.c_str())
{
	if (!_database.is_open())
	{
		throw std::runtime_error("Couldn't open CSV database.");
	}
	
	if (!_fileInput.is_open())
	{
		throw std::runtime_error("Couldn't open file.");
	}

	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
	// _database.close();
	// _fileInput.close();
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	BitcoinExchange::parseDatabase()
{
	std::string	line;
	std::string	date;
	std::string	value;
	size_t		i;

	while (std::getline(_database, line))
	{
		line.find(',');
		date = line.substr(0, i);
		float = line.substr(i, en)
		
	}
}
