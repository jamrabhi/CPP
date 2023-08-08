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
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap b("ja");
	DiamondTrap	a = b;

	a.whoAmI();
	a.highFivesGuys();
	a.attack("Joe");
	a.beRepaired(10);
	a.guardGate();

	return (0);
}
