/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpRequest.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 15:58:00 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/23 16:34:22 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HttpRequest.hpp"
#include "HttpTypes.hpp"


HttpRequest::HttpRequest(const std::string& rawRequest) : _rawRequest(rawRequest)
{

}

eParseResult HttpRequest::parse()
{
	if (_isParsed == true)
		return (PARSE_ALREADY_DONE);
	//parse

	//if parsing fails
	{
		//set _errorStatusCode
		//return PARSE_ERROR or PARSE_INCOMPLETE
	}
	_isParsed = true;
	return(PARSE_SUCCESS);
}