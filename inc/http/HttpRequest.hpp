#pragma once

#include <string>
#include <cstddef>
#include "HttpTypes.hpp"

class HttpRequest
{
	private:
		std::string			_method;
		std::string			_requestTarget;
		std::string			_httpVersion;
		VectorPairString	_headers;
		std::string			_body;
	
		void clearRequest();

	public:
		HttpRequest();
		HttpRequest(const HttpRequest& other);
		HttpRequest& operator=(const HttpRequest& other);
		~HttpRequest();

		void setMethod(const std::string& method);
		void setRequestTarget(const std::string& requestTarget);
		void setHttpVersion(const std::string& httpVersion);
		void setHeaders(const VectorPairString& headers);
		void setBody(const std::string& body);

		const std::string& getMethod() const;
		const std::string& getRequestTarget() const;
		const std::string& getHttpVersion() const;
		const VectorPairString& getAllHeaders() const;
		const std::string& getBody() const;

		void addHeader(const PairString& singleHeader);
		VectorPairString searchHeaders(const std::string& headerName) const;

		void resetRequest();
};