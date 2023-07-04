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

#include "Zombie.hpp"

int	main()
{
	Zombie *horde;

	horde = zombieHorde(10, "zzz");
	for (int i = 0; i < 10; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
