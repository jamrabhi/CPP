/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:57:35 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/14 00:18:43 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <limits>

class ScalarConverter
{
	public:
		~ScalarConverter();

		ScalarConverter	&operator=(ScalarConverter const &rhs);

		class ConversionException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		static void	convert(std::string str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		const std::string	_str;
};

#endif
