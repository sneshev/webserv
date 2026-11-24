#include "Client.hpp"

Client::Client(int clientSocket) : _clientSocket(clientSocket), _isConnected(true)
{}

Client::~Client()
{
	// maybe it will never be unvalid fd?
	if (_clientSocket > 0)
		close(_clientSocket);
}

void Client::receiveData()
{
	// recve all possible bytes and send it to the http parser
}

void Client::sendData()
{}