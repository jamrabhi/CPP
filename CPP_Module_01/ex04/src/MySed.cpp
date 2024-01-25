/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:17:06 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/25 20:56:09 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

MySed::MySed(std::string filename, std::string s1, std::string s2) :
			_filename(filename), _s1(s1), _s2(s2)
{
}

MySed::~MySed()
{
}

int	MySed::replace()
{
	if(_s1.length() == 0)
	{
		std::cerr << "Error : <s1> must have at least 1 character" << std::endl;
		return (1);
	}
	std::ifstream infile(_filename.c_str());

	if (!infile.is_open())
	{
		std::cerr << "Error : file \"" << _filename
			<< "\" doesn't exist or cannot be opened" << std::endl;
		return (1);
	}
	std::string		outfile_name = _filename + ".replace";
	std::ofstream	outfile(outfile_name.c_str());
	std::string		line;
	
	if (!outfile.is_open())
	{
		std::cerr << "Error : couldn't save .replace file" << std::endl;
		return (1);
	}
	while(std::getline(infile, line))									//
	{																	//
		for (size_t found = line.find(_s1); found != std::string::npos;	//
				found = line.find(_s1, found))							// Not working properly !!
		{																// Infinite loop to fix
			line.erase(found, _s1.length());							// in the case where s1 and s2 are identical
			line.insert(found, _s2);									// ./mySed test "Sed" "Sed"
		}																//
		outfile << line << std::endl;									//
	}																	//
	outfile.close();
	infile.close();
	return (0);
}
