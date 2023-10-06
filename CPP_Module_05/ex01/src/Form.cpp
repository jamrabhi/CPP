/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:56:08 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/06 03:23:28 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Form::Form() : _name("Random"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form(std::string const name, int const toSign, int const toExec) : _name(name), _signed(false),
		_gradeToSign(toSign), _gradeToExec(toExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}


Form::Form(Form const &src) : _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	*this = src;
}

Form::~Form()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form " << rhs.getName() << " requires grade " << rhs.getToSign() <<
	" to be signed and grade " << rhs.getToExec() << " to be executed.";
	return (o);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

std::string	Form::getName() const
{
	return (_name);
}

bool		Form::getIsSigned() const
{
	return (_signed);
}

int			Form::getToSign() const
{
	return (_gradeToSign);
}

int			Form::getToExec() const
{
	return (_gradeToExec);
}

void		Form::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() > getToSign())
		throw GradeTooLowException();
	_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}
