/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:06:41 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/03/06 19:26:26 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

RPN::RPN(std::string expression) : _expression(expression)
{
	evalExpr();
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		_expression = rhs._expression;
		_numbers = rhs._numbers;
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	RPN::evalExpr()
{
	std::istringstream	iss_expr(_expression);
	std::string			token;
	
	while (iss_expr >> token)
	{
		if (isdigit(token[0]) && token.size() == 1)
			_numbers.push(atoi(token.c_str()));
		else if (token == "+" || token == "-" || token == "/" || token == "*")
			do_op(token[0]);
		else
			throw std::runtime_error("Error");
	}
	
	if (_numbers.size() != 1)
		throw std::runtime_error("Error : invalid expression");
	
	std::cout << _numbers.top() << std::endl;
}

void	RPN::do_op(char op)
{
	long	left_operand;
	long	right_operand;
	long	rt;
	
	if (_numbers.size() < 2)
		throw std::runtime_error("Error : not enough numbers");
	
	right_operand = _numbers.top();
	_numbers.pop();
	left_operand = _numbers.top();
	_numbers.pop();

	switch (op)
	{
		case '+':
			rt = left_operand + right_operand;
			break;
		case '-':
			rt = left_operand - right_operand;
			break;
		case '/':
			if (right_operand == 0)
				throw std::runtime_error("Error : division by zero");
			rt = left_operand / right_operand;
			break;
		case '*':
			rt = left_operand * right_operand;
			break;
	}
	
	if (rt > std::numeric_limits<int>::max() || rt < std::numeric_limits<int>::min())
		throw (std::runtime_error("Error : result overflows int limit"));
	else
		_numbers.push(rt);
}
