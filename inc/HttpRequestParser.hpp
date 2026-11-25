#pragma once

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
		int _errorStatusCode = 0;

	public:
		HttpRequestParser();
		~HttpRequestParser();
}