/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:56:05 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/06 03:38:41 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string const name, int toSign, int toExec);
		AForm(AForm const &src);
		~AForm();

		AForm	&operator=(AForm const &rhs);

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getToSign() const;
		int				getToExec() const;
		void			beSigned(Bureaucrat &bc);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
