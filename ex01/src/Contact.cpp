/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:02:35 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/29 14:32:14 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <algorithm>
#include <sstream>

void Contact::setFirstName(const std::string& first_name)
{
	this->_first_name = first_name;
}

void Contact::setLastName(const std::string& last_name)
{
	this->_last_name = last_name;
}

void Contact::setNickName(const std::string& nickname)
{
	this->_nickname = nickname;
}

void Contact::setDarkestSecret(const std::string& darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

void Contact::setPhoneNumber(const unsigned int& number)
{
	this->_number = number;
}

std::string	Contact::getFirstName() const
{
	return _first_name;
}

std::string	Contact::getLastName() const
{
	return _last_name;
}

std::string	Contact::getNickname() const
{
	return _nickname;
}

std::string	Contact::getDarkestSecret() const
{
	return _darkest_secret;
}

unsigned int	Contact::getPhoneNumber() const
{
	return _number;
}

/* -- Add Contact -- */

static bool	notDigit(unsigned char c)
{
	return !std::isdigit(c);
}

static bool	new_field(const std::string &prompt, std::string &input)
{
	input.clear();
	while (1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return (false);
		if (!input.empty())
			return (true);
		std::cout << "⚠️ Empty input, please try again." << std::endl;
	}
}

bool	Contact::addContact()
{
	std::string			input;
	std::stringstream	ss_input;
	unsigned int		number;

	if (!new_field("Firstname : ", input))
		return (false);
	this->setFirstName(input);
	if (!new_field("Lastname : ", input))
		return (false);
	this->setLastName(input);
	if (!new_field("Nickname : ", input))
		return (false);
	this->setNickName(input);
	if (!new_field("Darkest secret : ", input))
		return (false);
	this->setDarkestSecret(input);
	while (1)
	{
		if (!new_field("Number : ", input))
			return (false);
		if (std::find_if(input.begin(), input.end(), notDigit) == input.end())
			break;
		std::cout << "❌ Invalid number, Digit only allowed" << std::endl;
	}
	ss_input << input;
	ss_input >> number;
	this->setPhoneNumber(number);

	return (true);
}