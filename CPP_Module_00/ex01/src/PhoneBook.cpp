/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:25:33 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/05/27 22:25:35 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	
}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::AddContact()
{
	// int	i;

    for (int i = 7; i > 0; --i) // check si c good
    {
        m_contact[i] = m_contact[i - 1];
    }
	// for (i = 0; i < 8; i++)
	// {
	// 	if (m_contact[i].isEmpty() == true)
	// 		break;
	// }
	m_contact[0].defineContact();
	std::cout << std::endl << "Successfully registered" << std::endl << std::endl;
}

void	PhoneBook::SearchContact()
{
	int	index = -1;

	std::cout << std::setw(10) << "Index" << '|';
	std::cout << std::setw(10) << "First name" << '|';
	std::cout << std::setw(10) << "Last name" << '|';
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::string(9, '.') << i << '|';
		m_contact[i].showContactRecap();
		std::cout << std::endl; 
	}
	std::cout << "Enter the index to display :" << std::endl;
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // A check si avant ou apres
	if (std::cin.fail() || (index < 0 || index > 7))
	{
		std::cin.clear();
		std::cout << "Invalid input. Please enter a valid index." << std::endl; // A check si avant ou apres
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
		std::cout << "Index typed = '" << index << "'" << std::endl;
}
