/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:16:29 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/29 10:29:33 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <algorithm>
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool notDigit(unsigned char c)
{
	return !std::isdigit(c);
}

static bool	search(PhoneBook p)
{
	std::string	input;
	long int	index;
	
	p.displayContacts();
	if (p.getSize() == 0)
	{
		std::cout << "No contact are registered" << std::endl;
		return (true);
	}
	while (1)
	{
		std::cout << "Enter index (0-" << p.getSize() - 1 << "): ";
		std::getline(std::cin, input);
		if (!input.empty() && 
			std::find_if(input.begin(), input.end(), notDigit) == input.end())
		{
			index = std::strtol(input.c_str(), NULL, 10);
			if (index < 0 || index >= p.getSize())
				std::cout << "Out of range" << std::endl;
			else
			{
				p.searchContact(index);
				break ;
			}
		}
		else if (std::cin.eof())
			return (false);
		else
			std::cout << "Invalid input" << std::endl;
	}
	return (true);
}

bool	new_field(const std::string &prompt, std::string &input)
{
	input.clear();
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return false;
		if (!input.empty())
			return true;
		std::cout << "⚠️  Empty input, please try again." << std::endl;
	}
}

static bool	new_contact(Contact &c)
{
	std::string	input;

	if (!new_field("Firstname : ", input))
		return false;
	c.setFirstName(input);
	if (!new_field("Lastname : ", input))
		return false;
	c.setLastName(input);
	if (!new_field("Nickname : ", input))
		return false;
	c.setNickName(input);
	if (!new_field("Darkest secret : ", input))
		return false;
	c.setDarkestSecret(input);
	while (true)
	{
		if (!new_field("Number : ", input))
			return false;
		if (std::find_if(input.begin(), input.end(), notDigit) == input.end())
			break;
		std::cout << "❌ Invalid number, Digit only allowed" << std::endl;
	}
	c.setPhoneNumber(std::strtol(input.c_str(), NULL, 10));

	return true;
}

int	main(void)
{
	Contact		c;
	PhoneBook	p;
	std::string	input;

	while (1)
	{
		std::cout << "Command: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.compare("EXIT") == 0)
			break;
		else if (input.compare("ADD") == 0)
		{
			if (!new_contact(c))
				break;
			p.addContact(c);
		}
		else if (input.compare("SEARCH") == 0)
			if (!search(p))
				break;
	}
}
