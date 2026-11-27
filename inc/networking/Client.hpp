#pragma once

#include "networking.hpp"
#include "HttpRequestParser.hpp"
#include "HttpHandler.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"
#include "ServerConfig.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <exception>
#include <deque>

class Client
{
	private:
		int							_clientSocket;
		HttpRequestParser 			_httpParser;
		std::deque<HttpRequest>		_httpRequest;
		std::deque<HttpResponse>	_httpResponse;
		const ServerConfig& 		_config;

	public:
		Client(int clientSocket, const ServerConfig& config);
		~Client();

		void closeSocket();
		void receiveData();
		void sendData();
		void handleRequest();
		void handleResponse();
		void parseRequest();
		void createResponse();
};
