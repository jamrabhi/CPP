/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:34:27 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/04 22:59:12 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		(av[1]) = 0;
	}
	else
	{
		std::cerr << "Usage : ./btc data.csv" << std::endl;
		return (1);
	}
	return (0);
}
