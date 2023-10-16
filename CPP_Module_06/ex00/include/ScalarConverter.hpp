/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:57:35 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/16 20:03:13 by jamrabhi         ###   ########.fr       */
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

		class ConversionException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		static void	convert(std::string str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
		const std::string	_str;
};

#endif
