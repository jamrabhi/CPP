/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:43:47 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 20:40:31 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Intern	&Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

AForm	*Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm* (Intern::*pointerToFunc[3])(std::string) =
	{
		&Intern::createRobotomy,
		&Intern::createShrubbery,
		&Intern::createPresidential
	};

	std::string	forms[3] = 
	{	"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (this->*pointerToFunc[i])(target);
		}
	}
	std::cerr << "Error : form \"" << formName << "\" not recognized" << std::endl;
	return (NULL);
}
