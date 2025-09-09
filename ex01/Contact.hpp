/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:48:21 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/08 10:32:01 by abouclie         ###   ########.fr       */
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
		std::string	_number;
	public:
		Contact();
		
		void	setFirstName(const std::string& first_name);
		void	setLastName(const std::string& last_name);
		void	setPhoneNumber(const std::string& number);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getPhoneNumber() const;

		void	displayShort() const;
		void	displayFull() const;
};

#endif