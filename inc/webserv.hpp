#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# include <iostream>
# include <string>

//add more status codes https://www.rfc-editor.org/info/rfc9112/#section-3
enum e_Status_Code
{
	STATUS_OK = 200,
	BAD_REQUEST = 400,
	NOT_IMPLEMENTED = 501,
	URI_TOO_LONG = 414,
	UNAUTHORIZED_ERROR = 401,
	FORBIDDEN = 403,
	NOT_FOUND = 404,
	INTERNAL_SERVER_ERROR = 500
}; //make sorting algorithm for this?

#endif