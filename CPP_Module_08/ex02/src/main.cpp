
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:30:01 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/01/23 20:30:01 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "Check if values of stack s are the same" << std::endl;
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;

	std::cout << "Test by replacing MutantStack by list" << std::endl;
	std::list<int> mylist;

	mylist.push_back(5);
	mylist.push_back(17);

	std::cout << mylist.back() << std::endl;

	mylist.pop_back();

	std::cout << mylist.size() << std::endl;

	mylist.push_back(3);
	mylist.push_back(5);
	mylist.push_back(737);
	//[...]
	mylist.push_back(0);

	std::list<int>::iterator l_it = mylist.begin();
	std::list<int>::iterator l_ite = mylist.end();

	++l_it;
	--l_it;
	while (l_it != l_ite)
	{
		std::cout << *l_it << std::endl;
		++l_it;
	}

	return (0);
}
