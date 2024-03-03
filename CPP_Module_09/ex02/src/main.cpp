/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:19:39 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/28 23:08:33 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <PmergeMe.hpp>

int	main(int ac, char *av[])
{
	if (ac > 2)
	{
		try
		{
			PmergeMe pm (ac,av);
		}
		catch (const std::exception &e)
		{
			std::cout << "Error : " << e.what() << std::endl;
			return (1);
		}	
	}
	else
	{
		std::cout << "Usage : ./PmergeMe <positive integer sequence>" << std::endl;
		return (1);
	}
	return (0);
}