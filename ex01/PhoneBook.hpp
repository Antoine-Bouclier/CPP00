/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:48:32 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/26 14:13:44 by abouclie         ###   ########lyon.fr   */
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
		~PhoneBook();
		void	addContact(const Contact& c);
		void	displayContacts() const;
		void	searchContact(int index) const;
		int		getSize() const;
};

#endif