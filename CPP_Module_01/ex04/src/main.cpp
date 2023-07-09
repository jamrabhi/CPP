/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:52:15 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/02 16:52:17 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

int main(int ac, char *av[])
{
	if (ac == 4)
	{
		MySed mysed(av[1], av[2], av[3]);
		return(mysed.replace());
	}
	else
	{
		std::cerr << "Usage : ./mySed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	return (0);
}
