/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:58:24 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/20 00:43:02 by jamrabhi         ###   ########.fr       */
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
		for (U i = 0; i < length; i++)
		{
			function(address[i]);
		}
	}
}

#endif