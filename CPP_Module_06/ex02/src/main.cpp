/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:21:06 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/10/16 21:54:00 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>


Base	*generate()
{
	std::srand(std::time(0));
	int randomValue = std::rand() % 3;

	if (randomValue == 0)
		return (new A);
	else if (randomValue == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	A	*AInstance;
	B	*BInstance;
	C	*CInstance;

	AInstance = dynamic_cast<A*>(p);
	if (AInstance != 0)
		std::cout << "A" << std::endl;
	
	BInstance = dynamic_cast<B*>(p);
	if (BInstance != 0)
		std::cout << "B" << std::endl;

	CInstance = dynamic_cast<C*>(p);
	if (CInstance != 0)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	A	AInstance;
	B	BInstance;
	C	CInstance;

	try
	{
		AInstance = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		BInstance = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		CInstance = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int	main()
{
	Base	*generated;

	generated = generate();

	identify(generated);
	identify(*generated);

	delete generated;
	return (0);
}
