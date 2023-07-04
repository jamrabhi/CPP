/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:53:50 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/02 16:53:51 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:

		Zombie(std::string name);
		~Zombie();
		void announce(void);

	private:

		std::string name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
