/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:43:22 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/11 21:20:00 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main()
{
	int myints[] = {9, 42, 5, 212};
	
	// Creation of my vector
	std::vector<int> v(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "Content of my vector :";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << ' ' << *it;
	}
	std::cout << std::endl << std::endl;

	// Testing easyfind with my vector
	std::vector<int>::iterator v_it;
	std::cout << "Trying to find value 42 in my vector" << std::endl;
	try
	{
		v_it = easyfind(v, 42);
		std::cout << "42 was found" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << "Trying to find value 21 in my vector" << std::endl;
	try
	{
		v_it = easyfind(v, 21);
		std::cout << "Value found" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	// Creation of my list
	std::list<int> l(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "Content of my list :";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		std::cout << ' ' << *it;
	}
	std::cout << std::endl << std::endl;

	// Testing easyfind with my list
	std::list<int>::iterator l_it;
	std::cout << "Trying to find value 212 in my list" << std::endl;
	try
	{
		l_it = easyfind(l, 212);
		std::cout << "212 was found" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << "Trying to find value 0 in my list" << std::endl;
	try
	{
		l_it = easyfind(l, 0);
		std::cout << "Value found" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	return (0);
}
