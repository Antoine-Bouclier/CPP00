/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:16:29 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/27 10:28:05 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
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
	int			index;

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
			std::cout << "Entrez un index : ";
    		std::getline(std::cin, input);

    		try
			{
       			index = std::atoi(input);  // convertit string en int
        		p.searchContact(index);       // appel fonction avec l'entier
   			}
    		catch (const std::invalid_argument& e)
			{
        		std::cout << "Entrée invalide, ce n'est pas un entier !" << std::endl;
			}
    		catch (const std::out_of_range& e)
			{
        		std::cout << "Entrée invalide, nombre trop grand !" << std::endl;
			}
    	}
		else if (input == "EXIT")
			break;
	}

}
