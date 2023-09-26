/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:00:04 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/09/27 01:16:24 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	Animal	*animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	std::cout << std::endl;
	animals[0]->setIdea("I'm not a cat!");
	std::cout << animals[0]->getType() << " idea :" << animals[0]->getIdea() << std::endl;
	animals[5]->setIdea("I'm not a dog!");
	std::cout << animals[5]->getType() << " idea :" << animals[5]->getIdea() << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	
	std::cout << std::endl;
	Dog basic;
	{
		Dog tmp(basic);
	}

	std::cout << std::endl;
	Dog a;
	{
		Dog b = a;
	}
	
	std::cout << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	
	return 0;
}
