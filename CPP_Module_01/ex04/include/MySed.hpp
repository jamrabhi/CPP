/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:16:49 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/05 04:16:51 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSED_HPP
# define MYSED_HPP

#include <string>
#include <iostream>
#include <fstream>

class MySed
{
	public:
		MySed(char *filename, std::string s1, std::string s2);
		~MySed();

	private:
		char	*_filename;
		std::string	_s1;
		std::string	_s2;
};

#endif
