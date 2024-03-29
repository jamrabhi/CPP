/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:55:07 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 21:47:12 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
	AForm("Shrubbery Creation", 145,137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	AForm(src), _target(src.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() != true)
		throw FormNotSignedException();
	if (executor.getGrade() > getToExec())
		throw Bureaucrat::GradeTooLowException();

	std::string outfile_name = getTarget() + "_shrubbery";
	std::ofstream outfile(outfile_name.c_str());

	if (!outfile.is_open())
		throw std::ofstream::failure("couldn't open " + outfile_name);

	std::string tree =
	"          .     .  .      +     .      .          .\n"
	"     .       .      .     #       .           .\n"
	"        .      .         ###            .      .      .\n"
	"      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
	"          .      . \"####\"###\"####\"  .\n"
	"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
	"  .             \"#########\"#########\"        .        .\n"
	"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
	"     .     .  \"#######\"##\"#####\"##\"#######\"                  .\n"
	"                .\"##\"#####\"#####\"##\"           .      .\n"
	"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
	"      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
	"    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
	"            .     \"      000      \"    .     .\n"
	"       .         .   .   000     .        .       .\n"
	".. .. ..................O000O........................ ......";

	outfile << tree << std::endl;
	outfile.close();
}
