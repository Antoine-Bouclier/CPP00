/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:16:29 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/28 11:41:15 by abouclie         ###   ########lyon.fr   */
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

static void	search(PhoneBook p)
{
	std::string	input;
	long int	index;
	
	p.displayContacts();
	if (p.getSize() == 0)
	{
		std::cout << "No contact are registered" << std::endl;
		return;
	}
	std::cout << "Enter index (0-" << p.getSize() - 1 << "): ";
	std::getline(std::cin, input);
	while (1)
	{
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
		else
			std::cout << "Invalid input" << std::endl;
	}
}

std::string	new_field(std::string str)
{
	std::string	input;
	
	while (input.empty())
	{
		if (std::cin.eof())
			break;
		std::cout << str;
		std::getline(std::cin, input);
	}
	return (input);
}

static void	new_contact(Contact &c)
{
	std::string	input;
	
	c.setFirstName(new_field("Firstname : "));
	c.setLastName(new_field("Lastname : "));
	c.setNickName(new_field("Nickname : "));
	c.setDarkestSecret(new_field("Darkest secret : "));
	while (1)
	{
		if (std::cin.eof() || input.compare("EXIT") == 0)
			break;
		input = new_field("Number (Digit only): ");
		if (std::find_if(input.begin(), input.end(), notDigit) == input.end())
			break ;
	}
	c.setPhoneNumber(std::strtol(input.c_str(), NULL, 10));
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
			new_contact(c);
			p.addContact(c);
		}
		else if (input.compare("SEARCH") == 0)
			search(p);
	}
}
