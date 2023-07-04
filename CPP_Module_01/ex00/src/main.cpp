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
	Zombie zombie("zombie");
	
	zombie.announce();

	Zombie *newZ;

	newZ = newZombie("newZ");
	newZ->announce();
	delete newZ;

	randomChump("randomZ");
	return (0);
}
