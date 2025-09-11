/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:48:32 by abouclie          #+#    #+#             */
/*   Updated: 2025/09/11 10:34:12 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact _contacts[8];
		int _nextIndex;
		int _size;

	public:
		PhoneBook();
		
		void	setContact(const Contact& Contact);

		void addContact(const Contact& c);
		void displayContacts() const;
		void searchContact(int index) const;
};

#endif