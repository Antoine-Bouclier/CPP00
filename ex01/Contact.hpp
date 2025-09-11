/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:48:21 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/11 09:08:47 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_darkest_secret;
		std::string	_number;
	public:
		Contact();
		
		void	setFirstName(const std::string& first_name);
		void	setLastName(const std::string& last_name);
		void	setNickName(const std::string& nickname);
		void	setDarkestSecret(const std::string& darkest_secret);
		void	setPhoneNumber(const std::string& number);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getDarkestSecret() const;
		std::string getPhoneNumber() const;

		void	displayShort() const;
		void	displayFull() const;
};

#endif