/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:58:07 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/14 01:38:34 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <stdexcept>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &src);
		~Span();

		Span	&operator=(Span const &rhs);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		std::vector<int>	_data;

	private:
		unsigned int		_n;
};

#endif
