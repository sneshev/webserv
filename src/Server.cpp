#include "Server.hpp"

Server::Server()
{}

Server::~Server()
{
	if (_serverSocket > 0)
		close(_serverSocket);
}

void Server::createSocket()
{
	_serverSocket = socket(PF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);

	if (_serverSocket == ERROR)
		throw std::runtime_error("Couldn't create the server socket");
}

void Server::bindSocket()
{
	sockaddr_in sockadd{};
	sockadd.sin_family = PF_INET;
	sockadd.sin_port = htons(8080);
	sockadd.sin_addr.s_addr = INADDR_ANY;

	if (bind(_serverSocket, (sockaddr*)&sockadd, sizeof(sockaddr_in)) == ERROR)
		throw std::runtime_error("Couldn't bind the server socket");
}

void Server::listenSocket()
{
	if (listen(_serverSocket, SOMAXCONN) == ERROR)
		throw std::runtime_error("Failed to listen on socket server");
}

void Server::run()
{}

// ofcourse this function should only be called after poll
void Server::acceptClient()
{
	int clientSocket;

	clientSocket = accept(_serverSocket, nullptr, nullptr);
	if (clientSocket == ERROR)
		throw std::runtime_error("Failed to accept a client");

	Client client(clientSocket);
	_clients.push_back(client);
}

void Server::closeServer()
{
	// i should disconnect all clients (gracefully?)
}
