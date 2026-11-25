/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpRequest.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 15:58:00 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/25 15:01:56 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HttpRequest.hpp"
#include "StringUtils.hpp"


HttpRequest::HttpRequest()
{

}
HttpRequest::HttpRequest(const HttpRequest& other): _method(other._method),
	_requestTarget(other._requestTarget), _httpVersion(other._httpVersion),
	_headers(other._headers), _body(other._body)
{
}
HttpRequest& HttpRequest::operator=(const HttpRequest& other)
{
	if (this != &other)
	{
		_method = other._method;
		_requestTarget = other._requestTarget;
		_httpVersion = other._httpVersion;
		_headers = other._headers;
		_body = other._body;
	}
	return (*this);
}

HttpRequest::~HttpRequest()
{

}

void HttpRequest::setMethod(const std::string& method)
{
	_method = method;
}
void HttpRequest::setRequestTarget(const std::string& requestTarget)
{
	_requestTarget = requestTarget;
}
void HttpRequest::setHttpVersion(const std::string& httpVersion)
{
	_httpVersion = httpVersion;
}
void HttpRequest::setHeaders(const VectorPairString& headers)
{
	_headers = headers;
}
void HttpRequest::setBody(const std::string& body)
{
	_body = body;
}

const std::string& HttpRequest::getMethod() const
{
	return (_method);
}

const std::string& HttpRequest::getRequestTarget() const
{
	return(_requestTarget);
}
const std::string& HttpRequest::getHttpVersion() const
{
	return(_httpVersion);
}
const VectorPairString& HttpRequest::getAllHeaders() const
{
	return(_headers);
}
const std::string& HttpRequest::getBody() const
{
	return(_body);
}

void HttpRequest::addHeader(const PairString& singleHeader)
{
	_headers.push_back(singleHeader);
}

VectorPairString HttpRequest::searchHeaders(const std::string& headerName) const
{
	std::string name = lowerStr(headerName);
	VectorPairString result;

	for (const PairString& headerPair : _headers)
	{
		if (name == lowerStr(headerPair.first))
		{
			result.push_back(headerPair);
		}
	}
	return (result);
}