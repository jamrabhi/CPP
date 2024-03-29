/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:16:19 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 22:56:46 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat manu("Manu", 10);
	Bureaucrat mike("Mike", 1);
	Form formulaire("formulaire", 5, 5);

	std::cout << manu << std::endl << mike << std::endl << formulaire << std::endl;

	manu.signForm(formulaire);
	mike.signForm(formulaire);

	try
	{
		formulaire.beSigned(manu);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	return (0);
}