/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpRequest.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 14:07:07 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/25 14:08:01 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_REQUEST_HPP
# define HTTP_REQUEST_HPP

# include <string>
# include <cstddef>
# include "HttpTypes.hpp"

class HttpRequest
{
	private:
	std::string _method;
	std::string _requestTarget;
	std::string _httpVersion;
	VectorPairString _headers;
	/* Treat body as arbitrary bytes. Do not assume they are null-terminated or utf-8.
	if there is a need to inspect indivual byte values use unsigned char and
	access with operator[]. use .size() and NOT strlen()*/
	std::string _body; //

	public:
	HttpRequest();
	HttpRequest(const HttpRequest& other);
	HttpRequest& operator=(const HttpRequest& other);

	~HttpRequest();

	void setMethod(const std::string& method);
	void setRequestTarget(const std::string& requestTarget);
	void setHttpVersion(const std::string& httpVersion);
	void setHeaders(const VectorPairString& headers);
	void addHeader(const PairString& header);
	void setBody(const std::string& body);

	const std::string& getMethod() const;
	const std::string& getRequestTarget() const;
	const std::string& getHttpVersion() const;
	const VectorPairString& getAllHeaders() const;
	VectorPairString searchHeaders(const std::string& headerName) const;
	const std::string& getBody() const;

};

#endif

