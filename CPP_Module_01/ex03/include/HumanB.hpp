/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:50:35 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/04 22:50:38 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
