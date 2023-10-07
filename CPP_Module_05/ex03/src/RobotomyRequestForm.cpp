/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:55:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 22:01:24 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	AForm("Robotomy Request", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	AForm(src), _target(src.getTarget())
{
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

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() != true)
		throw FormNotSignedException();
	if (executor.getGrade() > getToExec())
		throw Bureaucrat::GradeTooLowException();

	std::srand(std::time(0));
	int randomValue = std::rand();
	if (randomValue < RAND_MAX / 2)
	{
		std::cout << "DRDRDRDRRDDRDRDRDRDRRRDRD" << std::endl;
		std::cout << getTarget() << " has been robotomized !" << std::endl;
	}
	else
	{
		std::cout << getName() << " failed to robotomize " <<
		getTarget() << " !" << std::endl;
	}
}
