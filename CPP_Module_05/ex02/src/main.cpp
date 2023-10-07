/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:16:19 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 22:00:31 by jamrabhi         ###   ########.fr       */
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
	boss.signForm(shrub);
	try
	{
		shrub.execute(noob);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << noob.getName() << " couldn't execute form " 
		<< shrub.getName() << " because " << e.what() << std::endl;
	}
	boss.executeForm(shrub);

	std::cout << std::endl;

	RobotomyRequestForm robotomy("Robotomy_target");
	boss.signForm(robotomy);
	noob.executeForm(robotomy);
	boss.executeForm(robotomy);

	std::cout << std::endl;

	PresidentialPardonForm president("President_target");
	boss.signForm(president);
	noob.executeForm(president);
	boss.executeForm(president);
	
	return (0);
}
