/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:16:29 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/29 16:16:37 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

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
	long int	index;

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
		{
			p.displayContacts();
			while (1)
			{
				std::cout << "Entrez un index : ";
				std::cin >> input;
				
				index = std::strtol(input.c_str(), NULL, 10);
				std::cout << index << std::endl;
				if (index > 7 || index < 0)
					std::cout << "Out of range" << std::endl;
				else
				{
					p.searchContact(index);
					break;
				}
			}
		}
		else if (input == "EXIT")
			break;
	}

}
