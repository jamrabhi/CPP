/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:13:36 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/19 22:00:44 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void	decrement(T &i)
{
	i--;
}

int	main()
{
	int	nb[5] = {42,43,44,45,46};

	for (int i = 0; i < 5; i++)
		std::cout << nb[i] << " ";
	std::cout << std::endl;

	iter(&nb[0], 5, decrement);
	
	for (int i = 0; i < 5; i++)
		std::cout << nb[i] << " ";
	std::cout << std::endl;
	
	return (0);
}