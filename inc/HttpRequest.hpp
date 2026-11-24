/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaepark <yaepark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:07:07 by yaepark           #+#    #+#             */
/*   Updated: 2026/11/24 14:11:02 by yaepark          ###   ########.fr       */
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
	std::string _body; //(1)

	public:
	//constructor
	HttpRequest();
	HttpRequest(const HttpRequest& other);
	HttpRequest& operator=(const HttpRequest& other);

	//deconstructor
	~HttpRequest();

	//setters
	void setMethod(const std::string& method);
	void setRequestTarget(const std::string& requestTarget);
	void setHttpVersion(const std::string& httpVersion);
	void setHeaders(const VectorPairString& headers);
	void addHeader(const PairString& header);
	void setBody(const std::string& body);

	//getter
	const std::string& getMethod() const;
	const std::string& getRequestTarget() const;
	const std::string& getHttpVersion() const;
	const VectorPairString& getAllHeaders() const;
	VectorPairString searchHeaders(const std::string& headerName) const;
	const std::string& getBody() const;

};

#endif
/* (1) Treat as arbitrary bytes. do not assume they are null-terminated or utf-8.
	if there is a need to inspectindivual byte values use unsigned char and
	access with operator[]. use .size() and NOT strlen()*/
