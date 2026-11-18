# pragma once

#include "HttpResponse.hpp"
#include <string>
#include <iostream>
#include <vector>

class HttpResponseBuilder
{
	public:
	const enum eResponse
	{
		STATUS_LINE,
		FIELD_LINE,
		MESSAGE_BODY,
		RESPONSE_LINE_COUNT
	};

	protected:
	bool is_complete;
	bool is_empty;
	std::array<std::string, RESPONSE_LINE_COUNT> response_array;
	std::string complete_response;

	private:
	std::string status_line_;
	std::string response_header_;
	std::string response_body_;
};