/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:02:35 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/08 10:33:15 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {

}

void Contact::setFirstName(const std::string& first_name) {
	this->_first_name = first_name;
}

void Contact::setLastName(const std::string& last_name) {
	this->_last_name = last_name;
}

void Contact::setPhoneNumber(const std::string& number) {
	this->_number = number;
}

std::string Contact::getFirstName() const {
	return _first_name;
}

std::string Contact::getLastName() const {
	return _last_name;
}

std::string Contact::getPhoneNumber() const {
	return _number;
}

int	main()
{
	Contact c;

	c.setFirstName("Jean");
	c.setLastName("Dupont");
	c.setPhoneNumber("0123456789");

	std::cout << "Prénom : " << c.getFirstName() << std::endl;
	std::cout << "Nom : " << c.getLastName() << std::endl;
	std::cout << "Téléphone : " << c.getPhoneNumber() << std::endl;

	return 0;
}