/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:42:33 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/05/27 22:42:37 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::~Contact()
{

}

bool	Contact::isEmpty()
{
	if (m_first_name.size() == 0)
		return (true);
	return (false);
}

void	Contact::defineContact()
{
	std::cout << "Enter your first name :" << std::endl;
	std::getline(std::cin, m_first_name);
	// std::cout << "Enter your last name :" << std::endl;
	// std::getline(std::cin, m_last_name);
	// std::cout << "Enter your nickname :" << std::endl;
	// std::getline(std::cin, m_nickname);
	// std::cout << "Enter your phone number :" << std::endl;
	// std::getline(std::cin, m_phone);
	// std::cout << "Enter your darkest secret :" << std::endl;
	// std::getline(std::cin, m_secret);
}

void	Contact::showContactRecap()
{
	// std::cout << std::string(m_first_name, )
}
