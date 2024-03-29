/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:16:01 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 21:52:25 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

Bureaucrat::Bureaucrat() : _name("Random"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()),
	_grade(src.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade() const
{
	return (_grade);
}

void		Bureaucrat::incrementGrade()
{
	if (_grade < 2)
		throw GradeTooHighException();
	_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (_grade > 149)
		throw GradeTooLowException();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("bureaucrat grade is too high !");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("bureaucrat grade is too low !");
}

void		Bureaucrat::signForm(AForm &fm)
{
	try
	{
		fm.beSigned(*this);
		std::cout << getName() << " signed " << fm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << getName() << " couldn't sign " << fm.getName()
		<< " form because " << e.what() << "." << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed form " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << getName() << " couldn't execute form " <<
		form.getName() << " because " << e.what() << std::endl;
	}
}
