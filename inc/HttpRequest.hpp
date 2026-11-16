/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpRequest.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 14:07:07 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/16 16:57:37 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>


//needs to handle: request line, headers, emptylines, and optional message body
class HttpRequest
{
	private:
	std::string http_method_; // GET POST or DELETE
	std::string requested_resource_;
	std::string http_version_;
	std::string server_hostname_;
	std::string expected_response_format_;
	std::string client_information_;

	public:

	//constructor
	HttpRequest();
	HttpRequest(const HttpRequest& other);
	HttpRequest& operator=(const HttpRequest& other);
	HttpRequest(std::string request);

	//deconstructor
	~HttpRequest();

};