/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 05:28:22 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 05:34:47 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal const &src);
		virtual	~AAnimal();

		AAnimal 	&operator=(AAnimal const &rhs);

		std::string			getType() const;
		virtual void		makeSound() const = 0;
		virtual void		setIdea(std::string idea) = 0;
		virtual std::string	getIdea() const = 0;

	protected:
		std::string		type;
};

#endif
