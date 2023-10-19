/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:58:24 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/19 22:01:06 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
# define INTER_HPP

# include <iostream>

template<typename T, typename U>
void	iter(T *address, U length, void (*function)(T &))
{
	if (address && length && function)
	{
		for (int i = 0; i < length; i++)
		{
			function(address[i]);
		}
	}
}

#endif