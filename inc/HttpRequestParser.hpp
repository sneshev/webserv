# pragma once

#include <string>
#include <iostream>

class HttpRequestParser
{
	public:
	//enum
	const enum eMethodType
	{
		GET,
		POST,
		DELETE,
		INVALID
	};
	const enum eRequestTargetForm
	{
		ORIGIN_FORM,
		ABSOLUTE_FORM,
		AUTHORITY_FORM //ASTERISK_FORM is for OPTIONS request method, so will not implement
	};
	const enum eParsedRequest
	{
		METHOD,
		REQUEST_TARGET,
		PROTOCOL_VERSION,
		TARGET_URI,
		MESSAGE_BODY,
		PARSED_REQUEST_LINE_COUNT
	};
	const enum eRequestError
	{
		MOVED_PERMANENTLY_301,
		BAD_REQUEST_400,
		URI_TOO_LONG_414,
		NOT_IMPLEMENTED_501,
	};
	protected:
	bool is_parsed_;
	bool is_valid_;

	private:

};