/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:44:26 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/24 01:15:35 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array	&operator=(Array const &rhs);
		T		&operator[](unsigned int index) const;

		class			IndexException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		unsigned int	size() const;

	private:
		unsigned int	_size;
		T				*_data;
		
};

# include "Array.tpp"

#endif
