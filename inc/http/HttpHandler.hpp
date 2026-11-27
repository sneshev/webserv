#pragma once

# include "HttpTypes.hpp"

class HttpRequest;
class HttpResponse;
class ServerConfig;

class HttpHandler
{
	private:
		HttpHandler();
		HttpHandler(const HttpHandler& other);
		HttpHandler& operator=(const HttpHandler& other);

		const ServerConfig& _config;

	public:
		HttpHandler(const ServerConfig& config);
		~HttpHandler();

	/* Handles request using one of the allowed methods: GET, POST, DELETE
		Adds default headers, set connection-related headers, ensure response headers
		are consistent,  builds the request, and serializes it for sending
		saves response to _response */
		const HttpResponse& handleRequest(const HttpRequest& request);
		const HttpResponse& createErrorResponse(int statusCode);
};