/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:16:19 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/06 23:52:57 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat noob("Noob", 150);
	std::cout << boss << std::endl << noob << std::endl << std::endl;

	ShrubberyCreationForm shrub("Shrub_target");
	std::cout << shrub << std::endl;
	noob.signForm(shrub);
	try
	{
		shrub.execute(noob);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << noob.getName() << " couldn't execute form because " 
		<< shrub.getName() << e.what() << '\n';
	}
	noob.executeForm(shrub);
	boss.signForm(shrub);
	boss.executeForm(shrub);

	std::cout << std::endl;

	RobotomyRequestForm robotomy("Robotomy_target");
	noob.signForm(robotomy);
	noob.executeForm(robotomy);
	boss.signForm(robotomy);
	boss.executeForm(robotomy);

	std::cout << std::endl;

	PresidentialPardonForm president("President_target");
	noob.signForm(president);
	noob.executeForm(president);
	boss.signForm(president);
	boss.executeForm(president);
	
	return (0);
}
