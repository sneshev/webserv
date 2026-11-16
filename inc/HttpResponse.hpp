/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpResponse.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 16:18:25 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/16 16:57:50 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class HttpResponse
{
	private:
	std::string complete_request_;
	std::string status_line_;
	std::string response_headers_;
	std::string response_body_;

	public:
	//constructor
	HttpResponse();
	HttpResponse(const HttpResponse& other);
	HttpResponse& operator=(const HttpResponse& other);

	//deconstructor
	~HttpResponse();

	//getters
	std::string& getCompleteResponse();
};