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

std::string filterInput(const std::string str)
{
	std::string filteredInput;
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (std::isalnum(str[i]) || str[i] == ' ' || str[i] == '-')
			filteredInput += str[i];
	}
	return (filteredInput);
}

void	Contact::defineContact()
{
	std::cout << "Enter your first name :" << std::endl;
	std::getline(std::cin >> std::ws, m_first_name);
	m_first_name = filterInput(m_first_name);
	std::cout << "Enter your last name :" << std::endl;
	std::getline(std::cin >> std::ws, m_last_name);
	m_last_name = filterInput(m_last_name);
	std::cout << "Enter your nickname :" << std::endl;
	std::getline(std::cin >> std::ws, m_nickname);
	m_nickname = filterInput(m_nickname);
	std::cout << "Enter your phone number :" << std::endl;
	std::getline(std::cin >> std::ws, m_phone);
	m_nickname = filterInput(m_nickname);
	std::cout << "Enter your darkest secret :" << std::endl;
	std::getline(std::cin >> std::ws, m_secret);
	m_secret = filterInput(m_secret);
}

std::string truncateString(const std::string str, size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return (str);
}

void	Contact::showContactRecap()
{
	std::cout << std::setfill('.');
	std::cout << std::setw(10) << truncateString(m_first_name, 10) << '|'; 
	std::cout << std::setw(10) << truncateString(m_last_name, 10) << '|'; 
	std::cout << std::setw(10) << truncateString(m_nickname, 10);
	std::cout << std::setfill(' ');
}

