/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:57:46 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/10 20:35:14 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage : ./convert \"arg\"" << std::endl;
	}
	else
	{
		ScalarConverter::convert(argv[1]);
	}
	return (0);
}