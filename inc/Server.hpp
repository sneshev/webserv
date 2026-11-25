#pragma once

#include "Client.hpp"
#include <vector>
#include <exception>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>

class Server
{
	private:
		int					_serverSocket;
		std::vector<Client> _clients;

	public:
		Server();
		~Server();

		void run();

	private:
		void createSocket();
		void bindSocket();
		void listenSocket();
		void acceptClient();
		void closeServer();

};
