/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:56:08 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/05 18:52:55 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::string AForm::_name;

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

AForm::AForm() : _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	_name = "Random";
}

AForm::AForm(std::string name, int toSign, int toExec) : _signed(false),
		_gradeToSign(toSign), _gradeToExec(toExec)
{
	_name = name;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}


AForm::AForm(AForm const &src) : _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	*this = src;
}

AForm::~AForm()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

AForm	&AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << "Form " << rhs.getName() << " requires grade " << rhs.getToSign() <<
	" to be signed and grade " << rhs.getToExec() << " to be executed.";
	return (o);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

std::string	AForm::getName()
{
	return (_name);
}

bool		AForm::getIsSigned() const
{
	return (_signed);
}

int			AForm::getToSign() const
{
	return (_gradeToSign);
}

int			AForm::getToExec() const
{
	return (_gradeToExec);
}

void		AForm::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() > getToSign())
		throw GradeTooLowException();
	_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}
