/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:10:24 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/25 21:42:20 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &src);
		virtual ~MutantStack();

		MutantStack	&operator=(MutantStack const &rhs);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

	private:
		
};

# include "MutantStack.tpp"

#endif
