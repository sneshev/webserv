#pragma once

#include "Client.hpp"
#include <vector>

class Server
{
	private:
		int					_server;
		std::vector<Client> _clients;

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
