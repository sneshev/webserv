/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequestParser.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaepark <yaepark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:08:09 by yaepark           #+#    #+#             */
/*   Updated: 2026/11/26 19:04:55 by yaepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_REQUEST_PARSER_HPP
# define HTTP_REQUEST_PARSER_HPP

# include "HttpRequest.hpp"
# include <string>

enum eParseResult
{
	PARSE_SUCCESS,
	PARSE_ERROR,
	PARSE_INCOMPLETE,
};

class HttpRequestParser
{
	private:
	std::string _unparsedBuffer; //all unparsed bytes
	std::string _requestBuffer; //buffer of one complete request
	HttpRequest _parsedRequest;//object containing the parsed _requestBuffer
	int _errorStatusCode = 0;//0 for no error, and a non-zero status code if there is a parsing error

	public:
	HttpRequestParser();
	HttpRequestParser(const std::string& unparsedBuffer);

	HttpRequestParser(const HttpRequestParser& other);
	HttpRequestParser& operator=(const HttpRequestParser& other);

	~HttpRequestParser();

	/* 	Resets _errorStatusCode to zero.
		Clears _requestBuffer and resets _parsedRequest.
		Attempts to parse one complete HTTP request from _unparsedBuffer.
		PARSE_SUCCESS:
			Saves the raw request in _requestBuffer.
			Saves the parsed request in _parsedRequest.
			Removes the parsed bytes from _unparsedBuffer.
		PARSE_INCOMPLETE:
			No request is saved.
			_unparsedBuffer remains unchanged.
		PARSE_ERROR:
			No request is saved.
			_unparsedBuffer remains unchanged.
			Sets _errorStatusCode to the appropriate HTTP status code.
	*/
	eParseResult parseRequest();
	/*	Appends _unparsedBuffer with the string provided.*/
	void appendUnparsedBuffer(const std::string& nextBuffer);

	const std::string& getUnparsedBuffer() const;
	const std::string& getRequestBuffer() const;
	const HttpRequest& getParsedRequest() const;
	int getErrorStatusCode() const;
};

#endif