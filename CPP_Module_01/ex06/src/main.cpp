/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 03:12:51 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/10 03:12:53 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		Harl harl;

		harl.complain(av[1]);
	}
	else
	{
		std::cerr << "Usage : ./harlFilter <level>" << std::endl;
		return (1);
	}
	return (0);
}
