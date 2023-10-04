/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:16:19 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/04 20:33:35 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a("ABureaucrat", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("BBureaucrat", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	Bureaucrat randomA;
	std::cout << randomA << std::endl;
	try
	{
		randomA.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << randomA << std::endl;

	Bureaucrat c("CBureaucrat", 1);	
	std::cout << c << std::endl;
	try
	{
		c.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << c << std::endl;

	Bureaucrat d("Good", 42);
	std::cout << d << std::endl;
	try
	{
		d.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << d << std::endl;
	
	return (0);
}