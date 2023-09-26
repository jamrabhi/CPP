/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:02:44 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 01:15:05 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>
# include "Brain.hpp"


class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &src);
		virtual	~Cat();

		Cat 	&operator=(Cat const &rhs);

		virtual void		makeSound() const;
		virtual void		setIdea(std::string idea);
		virtual std::string	getIdea() const;
		
	private:
		Brain	*_brain;
};

#endif
