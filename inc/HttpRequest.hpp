/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpRequest.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 14:07:07 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/23 16:45:57 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_REQUEST_HPP
# define HTTP_REQUEST_HPP

# include <string>

# include "HttpTypes.hpp"

class HttpRequest
{
	public:
	//constructor
	HttpRequest(const HttpRequest& other);
	HttpRequest& operator=(const HttpRequest& other);
	HttpRequest(const std::string& rawRequest);

	//deconstructor
	~HttpRequest();

	//member function
	VectorPairString searchHeaders(const std::string& headerName) const;
	eParseResult parse(); //(3)

	//getter
	const std::string& getRawRequest() const;
	const std::string& getMethod() const;
	const std::string& getRequestTarget() const;
	const std::string& getHttpVersion() const;
	const VectorPairString& getAllHeaders() const;
	const std::string& getBody() const;
	int getErrorStatusCode()const;

	private:
	//default constructor should not be used
	HttpRequest();

	std::string _rawRequest;
	std::string _method;
	std::string _requestTarget;
	std::string _httpVersion;
	VectorPairString _headers;
	std::string _body; //(1)

	bool _isParsed = false; //(2)
	int _errorStatusCode = 0; //returns 0 for no error, and a non-zero status code if there is a parsing error

};

#endif
/* (1) Treat as arbitrary bytes. do not assume they are null-terminated or utf-8.
	if there is a need to inspectindivual byte values use unsigned char and
	access with operator[]. use .size() and NOT strlen()*/
/* (2) check if the request has been parsed. if false, use
	getErrorStatusCode() tocheck status code for error*/
/*(3) parses the _rawRequest. if parsing succeeds, or if the _rawRequest has already
	been parsed, returns PARSE_SUCCESS .If parsing fails, returns PARSE_ERROR.
	If the request is incomplete, returns PARSE_INCOMPLETE. Client must construct
	this class only when a complete request has arrived.
	Check _errorStatusCode for PARSE_ERROR status code (if applicable)*/
