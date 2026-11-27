#pragma once

#include <string>
#include "HttpTypes.hpp"

class HttpResponse
{
	private:
		std::string			_httpVersion;
		int					_statusCode = 0;
		std::string			_reasonPhrase;
		VectorPairString	_headers;
		std::string			_body;
		std::string			_serializedResponse;

		void clearResponse();

	public:
		HttpResponse();
		HttpResponse(const HttpResponse& other);
		HttpResponse& operator=(const HttpResponse& other);
		~HttpResponse();
	
		const std::string& serialize();
	
	
		bool	isValid() const;
		bool	isBuilt() const;
	
		void	addHeader(const PairString& header);
		void	setHeader(const PairString& header);
		void	removeHeader(const std::string& headerName);
		
		VectorPairString	searchHeaders(const std::string& headerName) const;
	
		const std::string&		getHttpVersion() const;
		int						getStatusCode() const;
		const std::string&		getReasonPhrase() const;
		const VectorPairString&	getAllHeaders() const;
		const std::string&		getBody() const;
	
		void	setHttpVersion(const std::string& version);
		void	setStatusCode(int code);
		void	setReasonPhrase(const std::string& phrase);
		void	setBody(const std::string& body);

};