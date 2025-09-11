/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:16:29 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/11 09:28:30 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
	std::string	input;

	while (1)
	{
		std::cout << "Command:";
		std::cin >> input;
		if (input == "ADD")
			new_contact(c);
		else if (input == "DISPLAY")
		{
			std::cout << "Firstname : " << c.getFirstName() << std::endl;
			std::cout << "Lastname : " << c.getLastName() << std::endl;
			std::cout << "nickname : " << c.getNickname() << std::endl;
			std::cout << "Darkest secret : " << c.getDarkestSecret() << std::endl;
			std::cout << "Number : " << c.getPhoneNumber() << std::endl;
		}
		else if (input == "EXIT")
			break;
	}

}
