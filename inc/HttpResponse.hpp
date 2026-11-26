/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaepark <yaepark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:18:25 by yaepark           #+#    #+#             */
/*   Updated: 2026/11/26 19:29:21 by yaepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_RESPONSE_HPP
# define HTTP_RESPONSE_HPP

# include <string>

# include "HttpTypes.hpp"

class HttpResponse
{
	private:
	std::string _httpVersion;
	int _statusCode = 0;
	std::string _reasonPhrase;
	VectorPairString _headers;
	std::string _body;

	std::string _serializedResponse; //serialized response to be sent over the network. cleared when any field is changed

	void clearResponse();

	public:
	HttpResponse();
	HttpResponse(const HttpResponse& other);
	HttpResponse& operator=(const HttpResponse& other);

	~HttpResponse();

	/* (1) Clears _serializedResponse.
	If isValid()==true, serializes the response into  std::string _serializedResponse.
	If serialization is not successful, clears _serializedResponse and returns empty string */
	const std::string& serialize();


	//checks enough fields are (validly) filled in to build a response
	bool isValid() const;
	//checks if _serializedResponse is not empty
	bool isBuilt() const;

	//appends a header. allows dupes. clears _serializedResponse
	void addHeader(const PairString& header);
	// replaces existing header(s) of the same headerName with the supplied header. clears _serializedResponse
	void setHeader(const PairString& header);
	//removes all occurance of a header. clears _serializedResponse
	void removeHeader(const std::string& headerName);
	//returns al matching headers. is case-insensitive
	VectorPairString searchHeaders(const std::string& headerName) const;

	const std::string& getHttpVersion() const;
	int getStatusCode() const;
	const std::string& getReasonPhrase() const;
	const VectorPairString& getAllHeaders() const;
	const std::string& getBody() const;

	//also clears _serializedResponse
	void setHttpVersion(const std::string& version);
	//also clears _serializedResponse
	void setStatusCode(int code);
	//also clears _serializedResponse
	void setReasonPhrase(const std::string& phrase);
	//also clears _serializedResponse
	void setBody(const std::string& body);

};
#endif
