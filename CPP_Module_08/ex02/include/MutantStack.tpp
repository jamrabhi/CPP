/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:10:20 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/25 21:08:03 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T> ()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src)
{
	*this = src;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
	if (this != &rhs)
	{
		this->c = rhs.c;
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}
