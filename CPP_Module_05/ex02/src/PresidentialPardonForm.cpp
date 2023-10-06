/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:55:13 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/06 23:52:12 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
	AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	AForm(src.getName(), 25, 5)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() != true)
		throw FormNotSigned();
	if (executor.getGrade() > getToExec())
		throw GradeTooLowException();

	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox !"
	<< std::endl;
}
