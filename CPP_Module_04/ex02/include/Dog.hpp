/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:02:16 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 05:30:02 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include <iostream>
# include <string>
# include "Brain.hpp"

class Dog : public AAnimal
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
