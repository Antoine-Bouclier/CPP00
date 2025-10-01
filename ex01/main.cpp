/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:16:29 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/01 10:52:04 by abouclie         ###   ########lyon.fr   */
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
	std::cin >> input;
	if (!input.empty() && 
		std::find_if(input.begin(), input.end(), notDigit) == input.end())
	{
		index = std::strtol(input.c_str(), NULL, 10);
		if (index < 0 || index >= p.getSize())
			std::cout << "Out of range" << std::endl;
		else
			p.searchContact(index);
	}
	else
		std::cout << "Invalid input" << std::endl;
}

static int	new_contact(Contact &c)
{
	std::string	input;

	std::cout << "Firstname : ";
	std::cin >> input;
	c.setFirstName(input);
	std::cout << "Lastname : ";
	std::cin >> input;
	c.setLastName(input);
	std::cout << "nickname :";
	std::cin >> input;
	c.setNickName(input);
	std::cout << "Darkest secret : ";
	std::cin >> input;
	c.setDarkestSecret(input);
	std::cout << "Number : ";
	std::cin >> input;
	c.setPhoneNumber(input);
	std::cout << "Contact registered" << std::endl;
	return (0);
}

int	main(void)
{
	Contact		c;
	PhoneBook	p;
	std::string	input;

	while (1)
	{
		std::cout << "Command:";
		std::cin >> input;
		if (input == "ADD")
		{
			new_contact(c);
			p.addContact(c);
		}
		else if (input == "SEARCH")
			search(p);
		else if (input == "EXIT")
			break;
	}
}
