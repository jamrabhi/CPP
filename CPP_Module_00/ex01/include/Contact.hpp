/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:42:08 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/05/27 22:42:11 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:

	Contact();
	bool isEmpty();
	~Contact();

	private:

	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone;
	std::string m_secret;
};

#endif
