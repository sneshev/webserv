#pragma once

#include <string>

class HttpRequest;
class HttpResponse;
class ServerConfig;

class HttpHandler
{
	private:
		HttpHandler();

		const ServerConfig& _config;

	public:
		HttpHandler(const ServerConfig& config);
		~HttpHandler();

		std::string handleRequest(const HttpRequest& request);
};