/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:24:45 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/05/27 22:24:47 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "cstdlib"

int	main()
{
	PhoneBook myphonebook;
	std::string	cmd;

	while (cmd.compare("EXIT") != 0)
	{
		std::cout << "Enter your command :" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
			myphonebook.AddContact();
		else if (cmd.compare("SEARCH") == 0)
			myphonebook.SearchContact();
		else if (std::cin.eof())
			exit(EXIT_FAILURE);
	}
	return (0);
}
