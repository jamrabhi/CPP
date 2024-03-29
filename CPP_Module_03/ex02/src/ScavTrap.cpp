/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:35:59 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/20 22:36:02 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

ScavTrap::ScavTrap() :	ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
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

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is dead! He can't attack " 
			<< target << std::endl;
	}
	else if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target <<
			", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " can't attack " << target
			<< ", not enough energy points" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << 
			" is dead! He can't enter in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << _name << 
			" is now in Gate keeper mode" << std::endl;
}
