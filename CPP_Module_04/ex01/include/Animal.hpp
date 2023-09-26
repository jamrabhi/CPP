/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:01:44 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 01:15:17 by jamrabhi         ###   ########.fr       */
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

		std::string			getType() const;
		virtual void		makeSound() const;
		virtual void		setIdea(std::string idea) = 0;
		virtual std::string	getIdea() const = 0;

	protected:
		std::string		type;
};

#endif
