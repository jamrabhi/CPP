/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:57:41 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/12 21:56:55 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	ScalarConverter::convert(std::string str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !isdigit(str[0]))
	{
		std::istringstream	newstr(str);
		char				char_conversion;

		newstr >> char_conversion;
		
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "char: '" << static_cast<char>(char_conversion) << "' " << std::endl;
		std::cout << "int: " << static_cast<int>(char_conversion) << std::endl;
		std::cout << "float: " << static_cast<float>(char_conversion) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(char_conversion) << std::endl;

	}
	else
	{
		std::istringstream	newstr(str);
		int				int_conversion;

		newstr >> int_conversion;
		
		std::cout << std::fixed << std::setprecision(1);
		if (std::isprint(static_cast<char>(int_conversion)))
			std::cout << "char: '" << static_cast<char>(int_conversion) << "' " << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(int_conversion) << std::endl;
		std::cout << "float: " << static_cast<float>(int_conversion) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(int_conversion) << std::endl;
	}
}
