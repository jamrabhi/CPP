/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:29:33 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/16 20:00:41 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
	int	mydata;
};

class Serializer
{
	public:
		~Serializer();

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const &src);

		Serializer	&operator=(Serializer const &rhs);
};

#endif
