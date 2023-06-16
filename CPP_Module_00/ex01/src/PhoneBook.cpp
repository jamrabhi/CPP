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
		{
			std::cout << "contact[" << i << "] is empty" << std::endl;
			break;
		}
	}
	m_contact[i].defineContact();
}
