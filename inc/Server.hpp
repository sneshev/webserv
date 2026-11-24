#pragma once

#include "Client.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <vector>

#define ERROR -1

class Server
{
	private:
		int					_serverSocket;
		std::vector<Client> _clients;
		int 				_clientCount;

	public:
		Server();
		~Server();

		void setupSocket();
		void bindSocket();
		void listenSocket();
		void run();
		void acceptClient();
		void closeServer();
};
