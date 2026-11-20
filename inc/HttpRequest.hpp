/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpRequest.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 14:07:07 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/20 15:52:47 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>

class HttpRequest
{
	public:
	//constructor
	HttpRequest(const HttpRequest& other);
	HttpRequest& operator=(const HttpRequest& other);
	HttpRequest(const std::string& raw_request); // gets request as string from person 1

	//deconstructor
	~HttpRequest();

	//member functions
	bool parse(); //returns is_parsed_

	//status checkers
	bool isParsed() const; // (2)
	int getStatusCode()const;

	//getters
	std::string& getRawRequest() const;
	std::string& getMethod() const;
	std::string& getRequestTarget() const;
	std::string& getHttpVersion() const;
	std::map<std::string, std::string>& getHeaders() const;
	std::string& getBody_() const;

	private:
	//default constructor shold not be used
	HttpRequest();
	std::string raw_request_;

	std::string method_;
	std::string request_target_;
	std::string http_version_;
	std::map<std::string, std::string> headers_;
	std::string body_; //(1)

	bool is_parsed_; // Was parsing succesful and complete?
	int status_code_;
};
/* (1) Treat as arbitrary bytes. do not assume they are null-terminated or utf-8.
	if there is a need to inspectindivual byte values use unsigned char and
	access with operator[]*/
/* (2) check if the request has been parsed. if false, use
	getStatusCode() tocheck status code for error*/