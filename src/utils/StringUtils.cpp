/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   StringUtils.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/25 14:53:51 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/25 14:57:22 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "StringUtils.hpp"
#include <cctype>


std::string lowerStr(const std::string& str)
{
	std::string result = str;

	for(char &c : result)
	{
		c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
	}

	return (result);
}