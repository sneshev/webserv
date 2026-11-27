#pragma once

#include "HttpRequest.hpp"
#include <string>

enum eParseResult
{
	PARSE_SUCCESS,
	PARSE_ERROR,
	PARSE_INCOMPLETE,
};

class HttpRequestParser
{
	private:
		std::string	_unparsedBuffer; //all unparsed bytes
		std::string	_requestBuffer; //buffer of one complete request
		HttpRequest	_parsedRequest;//object containing the parsed _requestBuffer
		int			_errorStatusCode = 0;//0 for no error, and a non-zero status code if there is a parsing error

	public:
		HttpRequestParser();
		HttpRequestParser(const std::string& unparsedBuffer);
		HttpRequestParser(const HttpRequestParser& other);
		HttpRequestParser& operator=(const HttpRequestParser& other);
		~HttpRequestParser();

		eParseResult	parseRequest();
		void			appendUnparsedBuffer(const std::string& nextBuffer);

		const std::string&	getUnparsedBuffer() const;
		const std::string &	getRequestBuffer() const;
		const HttpRequest&	getParsedRequest() const;
		int					getErrorStatusCode() const;
};