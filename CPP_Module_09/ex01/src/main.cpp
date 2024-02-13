/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:06:03 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/13 22:31:27 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		try
		{
			RPN rpn(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cout << "Usage : ./RPN \"expression\"" << std::endl;
	}
	return (0);
}
