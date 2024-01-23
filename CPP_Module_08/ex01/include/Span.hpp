/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:58:07 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/23 18:28:02 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <cstdlib>
# include <ctime>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &src);
		~Span();

		Span	&operator=(Span const &rhs);

		void	addNumber(int n);
		void	addNumbers(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);

		int		shortestSpan();
		int		longestSpan();

	private:
		unsigned int		_n;
		std::vector<int>	_data;
};

#endif
