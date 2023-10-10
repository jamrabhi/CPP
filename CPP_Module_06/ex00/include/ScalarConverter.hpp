/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:57:35 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/10 21:06:04 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	public:
		~ScalarConverter();

		ScalarConverter	&operator=(ScalarConverter const &rhs);

		static void	convert(std::string str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		const std::string	_str;
};

#endif
