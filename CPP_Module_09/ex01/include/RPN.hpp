/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:06:44 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/13 22:17:01 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <stdexcept>

class RPN
{
	public:
		RPN(std::string expression);
		RPN(RPN const &src);
		~RPN();

		RPN	&operator=(RPN const &rhs);

	private:
		void	evalExpr();
		void	do_op(char op);
		
		std::string		_expression;
		std::stack<int>	_numbers;
};

#endif
