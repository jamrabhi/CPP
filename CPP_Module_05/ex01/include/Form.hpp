/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:56:05 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/06 03:23:17 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string const name, int const toSign, int const toExec);
		Form(Form const &src);
		~Form();

		Form	&operator=(Form const &rhs);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getToSign() const;
		int			getToExec() const;
		void		beSigned(Bureaucrat &bc);

		class		GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class		GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;

};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
