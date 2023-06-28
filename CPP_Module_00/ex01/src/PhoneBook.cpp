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
	for (int i = 7; i > 0; --i)
		m_contact[i] = m_contact[i - 1];
	m_contact[0].DefineContact();
	std::cout << "\033[1;32mSuccessfully registered !\033[0m" << std::endl;
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
		m_contact[i].ShowContactRecap();
		std::cout << std::endl; 
	}
	std::cout << "Enter the index of the contact to display :" << std::endl;
	std::cin >> index;
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	else if (std::cin.fail() || (index < 0 || index > 7))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\033[1;31mInvalid input. Enter a valid index (between 0 and 7)\033[0m"
			<< std::endl;
		SearchContact();
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (m_contact[index].IsEmpty())
			std::cout << "\033[1;31mContact #" << index <<" is empty\033[0m" << std::endl;
		else
		{
			std::cout << "\033[1;34mContact #" << index << " details\033[0m" << std::endl;
			m_contact[index].ShowContactDetails();
		}
	}
}
