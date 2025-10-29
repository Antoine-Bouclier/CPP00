/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:48:15 by abouclie          #+#    #+#             */
/*   Updated: 2025/10/29 13:17:46 by abouclie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	std::string	str;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				str += static_cast<char>(std::toupper(argv[i][j]));
		}
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
