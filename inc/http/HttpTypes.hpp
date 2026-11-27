#pragma once

#include <string>
#include <vector>
#include <utility>

enum eStatusCode
{
	STATUS_OK = 200,
	STATUS_BAD_REQUEST = 400,
	STATUS_UNAUTHORIZED_ERROR = 401,
	STATUS_FORBIDDEN = 403,
	STATUS_NOT_FOUND = 404,
	STATUS_LENGTH_REQUIRED = 411,
	STATUS_CONTENT_TOO_LARGE = 413,
	STATUS_URI_TOO_LONG = 414,
	STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
	STATUS_INTERNAL_SERVER_ERROR = 500,
	STATUS_NOT_IMPLEMENTED = 501,
	STATUS_HTTP_VERSION_NOT_SUPPORTED = 505
};

using PairString = std::pair<std::string, std::string>;
using VectorPairString = std::vector<std::pair<std::string, std::string>>;