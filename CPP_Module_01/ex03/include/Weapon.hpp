/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:49:49 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/04 22:49:51 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string	getType();
		void				setType(std::string type);

	private:
		std::string	type;
};

#endif
