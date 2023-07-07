/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:17:06 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/05 04:17:07 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

MySed::MySed(char *filename, std::string s1, std::string s2) :
			_filename(filename), _s1(s1), _s2(s2)
{
	std::ofstream file(_filename);
	if (file.is_open())
	{
		file << "yep" << std::endl;
		file.close();
	}
	else
		std::cerr << "error couldn't open" << std::endl;
}

MySed::~MySed()
{
}


