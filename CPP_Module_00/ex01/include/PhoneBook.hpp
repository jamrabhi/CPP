/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:19:35 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/05/27 22:19:37 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include "Contact.hpp"

class	PhoneBook
{
	public:

	PhoneBook();
	void AddContact();
	void SearchContact();
	~PhoneBook();

	private:

	Contact m_contact[8];
};


#endif
