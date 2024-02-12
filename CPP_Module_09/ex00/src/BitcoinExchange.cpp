/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:34:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/12 22:30:34 by jamrabhi         ###   ########.fr       */
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
		throw std::runtime_error("could not open CSV database.");
	}
	if (!_fileInput.is_open())
	{
		_database.close();
		_dataMap.clear();
		throw std::runtime_error("could not open file.");
	}
	parseDatabase();
	parseInput();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
	_database.close();
	_fileInput.close();
	_dataMap.clear();
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_dataMap = rhs._dataMap;
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
	float		value;
	size_t		i = 0;

	std::getline(_database, line);
	while (std::getline(_database, line))
	{
		i = line.find(',');
		
		date = line.substr(0, i);
		value = atof(line.substr(++i).c_str());

		_dataMap.insert(std::pair<std::string, float>(date, value));
	}
}

void	BitcoinExchange::parseInput()
{
	std::string	line;
	int			nb_line = 0;

	while (std::getline(_fileInput, line))
	{
		if (nb_line == 0)
		{	
			if (line != "date | value")
				throw std::runtime_error("incorrect file format");
		}
		else try
		{
			checkInput(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		nb_line++;
	}
}

void	BitcoinExchange::checkInput(std::string line)
{
	std::string	date;
	float		value;
	size_t		i = 0;
	std::map<std::string, float>::iterator it_nearestDate;
	
	if (line.length() < 14)
		throw std::runtime_error("bad input => " + line);
	
	i = line.find('|');
	if (i == std::string::npos || i != 11 || line[10] != ' ' || line[12] != ' ')
		throw std::runtime_error("bad input => " + line);
	
	date = line.substr(0, i - 1);
	checkDate(date);
	
	value = atof(line.substr(13).c_str());
	checkValue(value);

	it_nearestDate = _dataMap.upper_bound(date);
	if (it_nearestDate->first != date && it_nearestDate != _dataMap.begin())
		--it_nearestDate;
	
	std::cout << date << " => " << value << " = " << (it_nearestDate->second * value)
		<< std::endl;
}

void	BitcoinExchange::checkDate(std::string date)
{
	unsigned int	year;
	unsigned int	month;
	unsigned int	day;
	
	if (date.length() != 10 || !isdigit(date[0]) || !isdigit(date[1]) ||
			!isdigit(date[2]) || !isdigit(date[3]) || date[4] != '-' ||
			!isdigit(date[5]) || !isdigit(date[6]) || date[7] != '-' ||
			!isdigit(date[8]) || !isdigit(date[9]))
		throw std::runtime_error("incorrect date format => " + date);
	
	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());
	if (year < 2009 || month > 12 || day > 31)
		throw std::runtime_error("incorrect date => " + date);
}

void	BitcoinExchange::checkValue(float value)
{
	if (value < 0)
		throw std::runtime_error("not a positive number.");
	if (value > 1000)
		throw std::runtime_error("too large a number.");
}
