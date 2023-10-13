/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:57:41 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/14 00:18:24 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

const char*	ScalarConverter::ConversionException::what() const throw()
{
	return ("conversion is impossible, please enter a char, int, float or double");
}

void	ScalarConverter::convert(std::string input)
{
	std::string	exceptions[] = {"-inf", "+inf", "-inff", "+inff",
		"nan", "nanf"};
	
	for (int i = 0; i < 6; i++)
	{
		if (input == exceptions[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(atof(input.c_str())) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(atof(input.c_str())) << std::endl;
			return ;
		}
	}

	if (input.length() == 1 && std::isprint(input[0]) && !isdigit(input[0]))
	{
		std::istringstream	newstr(input);
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
		for (size_t i = 0; i < input.length(); i++)
		{
			if (i == 0 && input[i] != '-' && input[i] != '+' && !isdigit(input[i])
				&& input[i] != '.')
				throw ConversionException();
			else if (i > 0 && !isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
				throw ConversionException();
		}
		
		std::istringstream	newstr(input);
		long double			nb_conversion;

		newstr >> nb_conversion;
		std::cout << std::fixed << std::setprecision(1);
		if (nb_conversion > 31 && nb_conversion < 127)
			std::cout << "char: '" << static_cast<char>(nb_conversion) << "' " << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (nb_conversion > std::numeric_limits<int>::max() ||
			nb_conversion < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nb_conversion) << std::endl;
		std::cout << "float: " << static_cast<float>(nb_conversion) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nb_conversion) << std::endl;
	}
}
