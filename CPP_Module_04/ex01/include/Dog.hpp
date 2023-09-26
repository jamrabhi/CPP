/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:02:16 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 01:14:20 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &src);
		virtual	~Dog();

		Dog 	&operator=(Dog const &rhs);

		virtual void		makeSound() const;
		virtual void		setIdea(std::string idea);
		virtual std::string	getIdea() const;
		
	private:
		Brain	*_brain;
};

#endif
