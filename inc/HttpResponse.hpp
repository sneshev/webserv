/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpResponse.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 16:18:25 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/25 14:06:21 by yaepark       ########   odam.nl         */
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

	std::string _completeResponse;

	void clearResponse();

	public:
	HttpResponse();
	HttpResponse(const HttpResponse& other);
	HttpResponse& operator=(const HttpResponse& other);

	~HttpResponse();

	/* (1) Clears _completeResponse.
	If isValid()==true, builds reponse
	Returns true if building is successful.
	If building  is not successful, clears _completeResponse and returns false */
	bool build();


	//checks enough fields are (validly) filled in to build a response
	bool isValid() const;
	//checks if _completeReponse is not empty
	bool isBuilt() const;

	//appends a header. allows dupes. clears _completeResponse
	void addHeader(const PairString& header);
	// replaces existing header(s) of the same headerName with the supplied header. clears _completeResponse
	void setHeader(const PairString& header);
	//removes all occurance of a header. clears _completeResponse
	void removeHeader(const std::string& headerName);
	//returns al matching headers. is case-insensitive
	VectorPairString searchHeaders(const std::string& headerName) const;

	const std::string& getHttpVersion() const;
	int getStatusCode() const;
	const std::string& getReasonPhrase() const;
	const VectorPairString& getAllHeaders() const;
	const std::string& getBody() const;
	const std::string& getCompleteResponse() const;

	//also clears _completeResponse
	void setHttpVersion(const std::string& version);
	//also clears _completeResponse
	void setStatusCode(int code);
	//also clears _completeResponse
	void setReasonPhrase(const std::string& phrase);
	//also clears _completeResponse
	void setBody(const std::string& body);

};
#endif
