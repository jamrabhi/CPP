/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:01:44 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/26 22:57:20 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		Animal();
		Animal(Animal const &src);
		virtual	~Animal();

		Animal 	&operator=(Animal const &rhs);

		std::string		getType() const;
		virtual void	makeSound() const;

	protected:
		std::string		type;
};

#endif
