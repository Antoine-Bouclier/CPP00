/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:16:29 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/29 14:35:30 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	Contact		c;
	PhoneBook	p;
	std::string	input;

	while (1)
	{
		std::cout << "Command: ";
		if (!std::getline(std::cin, input))
			return (1);
		if (std::cin.eof() || input.compare("EXIT") == 0)
			break;
		else if (input.compare("ADD") == 0)
		{
			if (!c.addContact())
				break;
			p.addContact(c);
		}
		else if (input.compare("SEARCH") == 0)
			if (!p.search())
				break;
	}
	return (0);
}
