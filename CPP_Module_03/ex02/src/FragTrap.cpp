/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:35:59 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/26 21:24:04 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

FragTrap::FragTrap() :	ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

void	FragTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is dead! He can't attack " 
			<< target << std::endl;
	}
	else if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target <<
			", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << _name << " can't attack " << target
			<< ", not enough energy points" << std::endl;
	}
}

void	FragTrap::guardGate()
{
	if (_hitPoints == 0)
		std::cout << "FragTrap " << _name << 
			" is dead! He can't enter in Gate keeper mode" << std::endl;
	else
		std::cout << "FragTrap " << _name << 
			" is now in Gate keeper mode" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " : Give me high five !" << std::endl;
}
