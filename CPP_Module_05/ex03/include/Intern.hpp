/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:42:40 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/07 20:05:35 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern	&operator=(Intern const &rhs);

		AForm	*makeForm(std::string formName, std::string target);
		AForm	*createRobotomy(std::string target);
		AForm	*createShrubbery(std::string target);
		AForm	*createPresidential(std::string target);

	private:
		
};

#endif
