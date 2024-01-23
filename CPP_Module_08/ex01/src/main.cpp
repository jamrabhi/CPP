/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:43:22 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/23 20:13:14 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	randomNumber()
{
	return (std::rand() % 200000);
}

int	main()
{
	std::cout << "**Tests from subject**" << std::endl;
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Test with a range of iterators
	
	std::cout << std::endl << "**Test with a range of iterators**" << std::endl;
	
	Span sp_it = Span(5);
	
	int myints[] = {16,2,77,29};
	std::vector<int> moreNumbers(myints, myints + sizeof(myints) / sizeof(int));

	sp_it.addNumbers(moreNumbers.begin(), moreNumbers.end());

	std::cout << sp_it.shortestSpan() << std::endl;
	std::cout << sp_it.longestSpan() << std::endl;
	
	std::cout << "Try to add again 4 elements" << std::endl;
	try
	{
		sp_it.addNumbers(moreNumbers.begin(), moreNumbers.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	
	// Test with 12000 numbers
	
	std::cout << std::endl << "**Test with 12 000 numbers**" << std::endl;
	
	Span big_sp = Span(12000);
	std::vector<int> big_v(12000);
	
	std::srand(std::time(0));
	std::generate(big_v.begin(), big_v.end(), randomNumber);
	
	big_sp.addNumbers(big_v.begin(), big_v.end());
	
	std::cout << big_sp.shortestSpan() << std::endl;
	std::cout << big_sp.longestSpan() << std::endl;
	std::cout << "Try to add 12001th element" << std::endl;
	try
	{
		big_sp.addNumber(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return (0);
}
