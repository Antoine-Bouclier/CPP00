/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 08:23:25 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/29 13:20:23 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
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
		std::cout << "        0" << i << "|"
				  << formatColumn(this->_contacts[i].getFirstName()) << "|"
				  << formatColumn(this->_contacts[i].getLastName()) << "|"
				  << formatColumn(this->_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::searchContact(int index) const
{
	if (index <= this->_size)
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