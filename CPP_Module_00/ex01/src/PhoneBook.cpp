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
	int	i;

	for (i = 0; i < 7; i++)
	{
		if (m_contact[i].isEmpty() == true)
			break;
	}
	// std::cout << "contact[" << i << "] is empty" << std::endl;
	m_contact[i].defineContact();
}

void	PhoneBook::SearchContact()
{
	std::cout << "     Index" << '|';
	std::cout << "First name" << '|';
	std::cout << " Last name" << '|';
	std::cout << "  Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << std::string(9, '.') << i << '|';
		m_contact[i].showContactRecap();
		std::cout << std::endl;
	}
}
