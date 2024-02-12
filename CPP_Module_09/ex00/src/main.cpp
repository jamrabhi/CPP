/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:34:27 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/12 22:30:10 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		try
		{
			BitcoinExchange	btc("data/data.csv", av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	return (0);
}
