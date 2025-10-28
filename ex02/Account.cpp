/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:05:24 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/28 11:06:25 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
	
}

Account::Account( int initial_deposit )
{
	/* init */
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
	
	/* Printing */
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";created" <<
	std::endl;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";closed" <<
	std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() <<
	std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";deposit:" << deposit << ";";
	
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	
	std::cout
		<< "amount:" << this->checkAmount()
		<< ";nb_deposits:" << this->_nbDeposits <<
	std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:"
		<< this->checkAmount()
		<< ";";

	if (this->checkAmount() < withdrawal)
	{
		std::cout
			<< "withdrawal:refused" <<
		std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		
		std::cout
			<< "withdrawal:" << withdrawal
			<< ";amount:" << this->checkAmount()
			<< ";nb_withdrawals:" << this->_nbWithdrawals <<
		std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals <<
	std::endl;
}

void	Account::_displayTimestamp( void )
{
	struct tm	datetime;
	time_t		timestamp;
	char		output[19];

	timestamp = std::time(&timestamp);
	datetime = *std::localtime(&timestamp);

	strftime(output, 19, "[%Y%m%d_%H%M%S] ", &datetime);
	std::cout << output;
}