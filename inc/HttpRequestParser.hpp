/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpRequestParser.hpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/24 12:08:09 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/25 14:08:08 by yaepark       ########   odam.nl         */
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
	HttpRequestParser();
	HttpRequestParser(const HttpRequestParser& other);
	HttpRequestParser& operator=(const HttpRequestParser& other);
	HttpRequestParser(const std::string& requestBuffer);

	~HttpRequestParser();

	/* (1) Resets  _bytesParsed & _errorStatusCode to zero.
	Parses the _requestBuffer and saves it into a HttpRequest object upon PARSE_SUCCESS.
	If a complete request is parsed, returns PARSE_SUCCESS._bytesParsed = size of the parsed Request
	Parsing fail will not save anything to the HttpRequest request object.
	If parsing fails because the request is incomplete, returns PARSE_INCOMPLETE._bytesParsed = 0
	If parsing fails due to an invalid request, returns PARSE_ERROR. _bytesParsed = 0 and sets _errorStatusCode.
	*/
	eParseResult parseRequest(HttpRequest& request);

	/*Appends _requestBuffer with the string provided.
	Can be used regardless of if _requestBuffer is empty.
	Sets _bytesParsed and & _errorStatusCode to zero 0.*/
	void appendRequestBuffer(const std::string& nextBuffer);
	/*Removes _bytesParsed number of bytes from the beginning of _requestBuffer
	Resets _bytesParsed and & _errorStatusCode to zero 0.*/
	void removeBytesParsed();

	const std::string& getRequestBuffer() const;
	size_t getBytesParsed() const;
	int getErrorStatusCode() const;

};


#endif



/* (3) 0 for no error, and a non-zero status code if there is a parsing error*/