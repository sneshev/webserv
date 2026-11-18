/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaepark <yaepark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:07:07 by yaepark           #+#    #+#             */
/*   Updated: 2026/11/18 14:31:55 by yaepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <array>
#include "HttpRequestParser.hpp"

//needs to handle: request line, headers, emptylines, and optional message body
class HttpRequest : public HttpRequestParser
{
	public:
	//constructor
	HttpRequest(const HttpRequest& other);
	HttpRequest& operator=(const HttpRequest& other);
	HttpRequest(const std::string& request); // gets request as string from person 1

	//deconstructor
	~HttpRequest();

	//status checkers
	bool checkIfParsed() const; // check if the request is finished parsing
	bool checkIsEmpty() const; //check if the class has a request to parse
	bool checkIsValid();
	eRequestError checkError();

	//member functions
	void parseRequest();

	//getters
	std::string getRawRequest() const;
	std::array<std::string, PARSED_REQUEST_LINE_COUNT> getParsedRequest() const;
	std::string& getParsedLine(const eParsedRequest parse_line);

	private:
	//default constructor shold not be used
	HttpRequest();

	bool is_empty_;
	std::string raw_request_;
	std::array<std::string, PARSED_REQUEST_LINE_COUNT> parsed_request_;
};