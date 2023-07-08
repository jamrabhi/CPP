/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:52:15 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/02 16:52:17 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

int main(int ac, char *av[])
{
	MySed mysed(av[1], av[2], av[3]);

	if (ac == 4)
		return(mysed.replace());

	// std::string	line = "salut je m'appelle jamal";
	// std::string s1 = "jamal";
	// std::string s2 = "younes";
	
	// std::cout << "before line = \"" << line << "\"" << std::endl;
	// for (size_t pos = 0; pos < line.length(); pos++)
	// 	{
	// 		if (line.compare(pos, s1.length(), s1) == 0)
	// 		{
	// 			line.erase(pos, s1.length());
	// 			line.insert(pos, s2);
	// 			pos += s1.length();
	// 		}
	// 	}
	// std::cout << " line = \"" << line << "\"" << std::endl;


	return (0);
}
