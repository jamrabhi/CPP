/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:35:59 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/27 02:45:21 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name) , ScavTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
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

void	DiamondTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "DiamondTrap " << _name << " is dead! He can't attack " 
			<< target << std::endl;
	}
	else if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "DiamondTrap " << _name << " attacks " << target <<
			", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "DiamondTrap " << _name << " can't attack " << target
			<< ", not enough energy points" << std::endl;
	}
}

void	DiamondTrap::guardGate()
{
	if (_hitPoints == 0)
		std::cout << "DiamondTrap " << _name << 
			" is dead! He can't enter in Gate keeper mode" << std::endl;
	else
		std::cout << "DiamondTrap " << _name << 
			" is now in Gate keeper mode" << std::endl;
}

void	DiamondTrap::highFivesGuys()
{
	std::cout << "DiamondTrap " << _name << " : Give me high five !" << std::endl;
}
