/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:55:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 02:37:01 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	AForm(src.getName(), 72, 45)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() != true)
		throw FormNotSignedException();
	if (executor.getGrade() > getToExec())
		throw GradeTooLowException();

	std::srand(std::time(0));
	int randomValue = std::rand();
	if (randomValue < RAND_MAX / 2)
	{
		std::cout << "DRDRDRDRRDDRDRDRDRDRRRDRD" << std::endl;
		std::cout << getName() << " has been robotomized !" << std::endl;
	}
	else
	{
		std::cout << "Robotomy " << getName() << " failed to robotomize " <<
		getName() << " !" << std::endl;
	}
}
