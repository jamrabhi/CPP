/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:44:26 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/11 21:14:16 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <stdexcept>

template<typename T>
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator	it;

	it = find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::out_of_range("Value not found");
	return (it);
}

#endif
