/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:29:23 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/16 19:58:28 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data data;
	data.mydata = 42;
	std::cout << "address of data		= " << &data << std::endl;
	std::cout << "content of data		= " << data.mydata << std::endl << std::endl;

	uintptr_t	raw;
	raw = Serializer::serialize(&data);
	std::cout << "data is serialized in raw" << std::endl << std::endl;

	Data *data_ptr;
	data_ptr = Serializer::deserialize(raw);
	std::cout << "address of data_ptr	= " << data_ptr << std::endl;
	std::cout << "content of data_ptr	= " << data_ptr->mydata << std::endl;
	return (0);
}
