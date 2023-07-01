/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:42:48 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/06/28 21:42:49 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit),
										_nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
		<< ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() 
		<< ";closed" << std::endl;
}

int		Account::getNbAccounts()
{
	return (_nbAccounts);
}

int		Account::getTotalAmount()
{
	return (_totalAmount);
}

int		Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int		Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << _totalAmount
		<< ";deposits:" << getNbDeposits() << ";withdrawals:" 
		<< getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount()
		<< ";deposit:" << deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	std::cout << ";amount:" << checkAmount() << ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount()
		<< ";withdrawal:";
	if (_amount - withdrawal > 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		std::cout << withdrawal << ";amount:" << checkAmount() 
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl; 
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

int		Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
		<< ";deposits:" << _nbDeposits << ";withdrawals:" 
		<< _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp()
{
	// std::cout << "[19920104_091532] ";
	time_t currentTime = std::time(0);
	char timestamp[16];
	tm* timeinfo;
	
	timeinfo = std::localtime(&currentTime);
	strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << timestamp << "] ";
}
