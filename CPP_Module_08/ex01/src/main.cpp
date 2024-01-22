/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:43:22 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/22 21:44:57 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp_it = Span(5);
	
	int myints[] = {16,2,77,29,98,65};
	std::vector<int> moreNumbers(myints, myints + sizeof(myints) / sizeof(int));

	sp_it.addNumbers(moreNumbers.begin(), moreNumbers.end());

	std::cout << sp_it.shortestSpan() << std::endl;
	std::cout << sp_it.longestSpan() << std::endl;
	return (0);
}
