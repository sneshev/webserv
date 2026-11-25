#pragma once

#include "networking.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <exception>

class Client
{
	private:
		int					_clientSocket;
		std::string 		_httpBuffer;
		std::string			_httpRequest;
		std::string			_httpResponse;
		bool				_responseReady;

	public:
		Client(int clientSocket);
		~Client();

		void closeSocket();
		void receiveData();
		void sendData();
		void handleRequest();
		void handleResponse();
};