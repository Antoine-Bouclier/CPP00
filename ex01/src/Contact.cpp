/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:02:35 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/27 12:52:54 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

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