/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:57:46 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/14 00:15:26 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage : ./convert \"arg\"" << std::endl;
	}
	else
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error :" << e.what() << std::endl;
		}
		
	}
	return (0);
}