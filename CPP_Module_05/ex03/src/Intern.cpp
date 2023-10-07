/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:43:47 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 04:03:58 by jamrabhi         ###   ########.fr       */
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

void	Intern::makeForm(std::string formName, std::string target)
{
	// void (Intern::*pointerToFunc[3])(void) =
	// {
	// 	&RobotomyRequestForm::RobotomyRequestForm(target),
	// 	&ShrubberyCreationForm::ShrubberyCreationForm(target),
	// 	&PresidentialPardonForm::PresidentialPardonForm(target)
	// };

	std::string	forms[3] = 
	{	"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
			(this->*pointerToFunc[i])();
	}
}
