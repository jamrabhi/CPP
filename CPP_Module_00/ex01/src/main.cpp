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

int	main()
{
	PhoneBook	myphonebook;
	std::string	cmd;

	while (cmd.compare("EXIT") != 0)
	{
		std::cout << "Enter your command :" << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		else if (cmd.compare("ADD") == 0)
			myphonebook.AddContact();
		else if (cmd.compare("SEARCH") == 0)
			myphonebook.SearchContact();
		else if (cmd.compare("EXIT") == 0)
			exit(EXIT_SUCCESS);
		else
			std::cout << "\033[1;31mInvalid command ! Enter a valid command (ADD, SEARCH or EXIT)\033[0m" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
