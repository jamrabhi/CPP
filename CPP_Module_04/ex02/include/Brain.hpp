/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:10:01 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 00:10:33 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain();
		Brain(Brain const &src);
		~Brain();

		Brain	&operator=(Brain const &rhs);
		
		std::string	ideas[100];
};

#endif
