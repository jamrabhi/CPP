/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:43:22 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/02 20:34:53 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <map>

int	main()
{
	std::map<const int, int> mymap;
	std::map<const int, int>::iterator it;

	mymap[0] = 42;
	mymap[1] = 24;
	mymap[2] = 94;

	it = easyfind(mymap, 1);
	// std::cout << it->second << std::endl;

	return (0);
}
