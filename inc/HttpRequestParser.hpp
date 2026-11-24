/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequestParser.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaepark <yaepark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:08:09 by yaepark           #+#    #+#             */
/*   Updated: 2026/11/24 15:25:57 by yaepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_REQUEST_PARSER_HPP
# define HTTP_REQUEST_PARSER_HPP

# include <string>
# include <cstddef>

class HttpRequest;

enum eParseResult
{
	PARSE_SUCCESS,
	PARSE_ERROR,
	PARSE_INCOMPLETE,
};

class HttpRequestParser
{
	private:
	std::string _requestBuffer;
	size_t _bytesParsed = 0;
	int _errorStatusCode = 0; //(3)

	public:
	//constructor
	HttpRequestParser();
	HttpRequestParser(const HttpRequestParser& other);
	HttpRequestParser& operator=(const HttpRequestParser& other);
	HttpRequestParser(const std::string& requestBuffer);

	//deconstructor
	~HttpRequestParser();

	//parsing
	eParseResult parseRequest(HttpRequest& request);//(1)

	//_requestBuffer manipulators
	void appendRequestBuffer(const std::string& next);
	void removeBytesParsed(); //(2)

	//getters
	const std::string& getRequestBuffer() const;
	size_t getBytesParsed() const;
	int getErrorStatusCode() const;

};


#endif

/* (1) Resets  _bytesParsed & _errorStatusCode to zero.
	Parses the _requestBuffer and saves it into a HttpRequest object upon PARSE_SUCCESS.
	If a complete request is parsed, returns PARSE_SUCCESS._bytesParsed = size of the parsed Request
	Parsing fail will not save anything to the HttpRequest request object.
	If parsing fails because the request is incomplete, returns PARSE_INCOMPLETE._bytesParsed = 0
	If parsing fails due to an invalid request, returns PARSE_ERROR. _bytesParsed = 0 and sets _errorStatusCode.

	*/
/* (2) Removes _bytesParsed number of bytes from the beginning of _requestBuffer
	Resets _bytesParsed and & _errorStatusCode to zero 0.*/
/* (3) 0 for no error, and a non-zero status code if there is a parsing error*/