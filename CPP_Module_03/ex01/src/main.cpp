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

int	main()
{
	ClapTrap a("Joe");
	ClapTrap b("Mike");
	ClapTrap c;

	a.attack("Mike");
	b.takeDamage(0);
	b.beRepaired(0);
	c.attack("Mike");

	return (0);
}
