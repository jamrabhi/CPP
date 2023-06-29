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

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_accountIndex++;
	_nbAccounts++;
}

Account::~Account()
{

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

}

void	Account::makeDeposit(int deposit)
{
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal > 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		return (true);
	}
	return (false);
}

int		Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{

}

void	Account::_displayTimestamp()
{

}
