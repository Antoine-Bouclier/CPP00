/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:02:35 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/11 10:29:47 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
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

void Contact::setPhoneNumber(const std::string& number)
{
	this->_number = number;
}

std::string Contact::getFirstName() const
{
	return _first_name;
}

std::string Contact::getLastName() const
{
	return _last_name;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string	Contact::getDarkestSecret() const
{
	return _darkest_secret;
}

std::string Contact::getPhoneNumber() const
{
	return _number;
}