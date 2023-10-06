/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:56:08 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/06 03:11:07 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

AForm::AForm() : _name("Random"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
}

AForm::AForm(std::string const name, int toSign, int toExec) : _name(name), _signed(false),
		_gradeToSign(toSign), _gradeToExec(toExec)
{
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

std::string	AForm::getName() const
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
