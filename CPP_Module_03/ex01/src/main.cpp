/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:27:08 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/12 00:27:10 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap a("Joe");
	ScavTrap b("Mike");

	a.attack("Mike");
	b.takeDamage(20);
	a.attack("Mike");
	b.takeDamage(20);
	a.attack("Mike");
	b.takeDamage(20);
	a.attack("Mike");
	b.takeDamage(20);
	a.attack("Mike");
	b.takeDamage(20);
	b.guardGate();
	return (0);
}
