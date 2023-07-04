/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:52:15 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/02 16:52:17 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address of str\t\t\t: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR\t: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF\t: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of str\t\t\t: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR\t: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF\t: " << stringREF << std::endl;
	return (0);
}
