/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:44:04 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/20 11:44:07 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

ClapTrap::ClapTrap() :	_name("Random"), _hitPoints(10), _energyPoints(10),
						_attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_name(name), _hitPoints(10),
										_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
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

void	ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead! He can't attack " 
			<< target << std::endl;
	}
	else if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target <<
			", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't attack " << target
			<< ", not enough energy points" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
	else
	{
		if (_hitPoints < amount)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		if (_hitPoints == 0)
			std::cout << "ClapTrap " << _name << " is now dead!" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " has been attacked! Remaining HP :"
			<< _hitPoints << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name <<
			" is already dead! He can't be repaired" << std::endl;
	}
	else if (_energyPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " has been repaired! New HP : "
			<< _hitPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " has not enough energy points! " <<
			"Remaining energy points : " << _energyPoints << std::endl;
	}
}
