/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 08:23:25 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/29 14:34:31 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <algorithm>
#include <sstream>

PhoneBook::PhoneBook() : _nextIndex(0), _size(0)
{

}

std::string formatColumn(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::addContact(const Contact& c)
{
	this->_contacts[_nextIndex] = c;
	_nextIndex = (_nextIndex + 1) % 8;
	if (_size < 8)
		_size++;
}

void PhoneBook::displayContacts() const
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < this->_size; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << formatColumn(this->_contacts[i].getFirstName()) << "|"
				  << formatColumn(this->_contacts[i].getLastName()) << "|"
				  << formatColumn(this->_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::searchContact(int index) const
{
	if (index >= 0 && index <= this->_size)
	{
		std::cout << "Firstname : " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "Lastname : " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "nickname : " << this->_contacts[index].getNickname() << std::endl;
		std::cout << "Darkest secret : " << this->_contacts[index].getDarkestSecret() << std::endl;
		std::cout << "Number : " << this->_contacts[index].getPhoneNumber() << std::endl;
	}
	else
		std::cout << "Index " << index << " doesnt exist" << std::endl;
}

bool notDigit(unsigned char c)
{
	return !std::isdigit(c);
}

bool PhoneBook::search() const
{
	std::string			input;
	std::stringstream	ss_input;
	long int			index;
	
	this->displayContacts();
	if (this->getSize() == 0)
	{
		std::cout << "No contact are registered" << std::endl;
		return (true);
	}
	while (1)
	{
		std::cout << "Enter index (0-" << this->getSize() - 1 << "): ";
		if (!std::getline(std::cin, input))
			return (false);
		if (!input.empty() && 
			std::find_if(input.begin(), input.end(), notDigit) == input.end())
		{
			ss_input << input;
			ss_input >> index;
			if (index < 0 || index >= this->getSize())
				std::cout << "Out of range" << std::endl;
			else
			{
				this->searchContact(index);
				break ;
			}
			ss_input.clear();
		}
		else if (std::cin.eof())
			return (false);
		else
			std::cout << "Invalid input" << std::endl;
	}
	return (true);
}

int	PhoneBook::getSize() const
{
	return _size;
}