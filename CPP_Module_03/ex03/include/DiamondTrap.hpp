/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:27:57 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/27 02:46:43 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap();

		DiamondTrap 	&operator=(DiamondTrap const &rhs);

		void	attack(const std::string &target);
		void	guardGate();
		void	highFivesGuys();
};

#endif
