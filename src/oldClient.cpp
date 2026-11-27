#include "Client.hpp"

Client::Client(int clientSocket) : _clientSocket(clientSocket), _responseReady(false)
{}

Client::~Client()
{
	closeSocket();
}

void Client::closeSocket()
{
	// will fd ever be invalid? The reason client exists is because socket creation was succesfull...
	// and i dont think we do any operations that would close the socket?
	if (_clientSocket > 0)
		close(_clientSocket);
}


// errors for recve:
// 0: client disconnected gracefully
// -1: error with errno EAGAIN/EWOULDBLOCK(no data available), EINTR(interupted by signal, try again)
// any other errno's?
void Client::receiveData()
{
	char	buf[4096];
	size_t	len;

	while (1)
	{
		len = recv(_clientSocket, buf, 4096, 0);

		if (len == 0)
			closeSocket();

		if (len == ERROR)
		{
			if (errno == EAGAIN || errno == EWOULDBLOCK)
				return ;
			if (errno == EINTR)
				continue ;
		}

		_httpBuffer += std::string(buf, len);
	}
}

void Client::sendData()
{
	while (1)
	{
		ssize_t byteCount = send(_clientSocket, _httpResponse.c_str(), _httpResponse.size(), 0);

		if (byteCount == 0)
			closeSocket();
		if (byteCount == ERROR)
		{
			// I SHOULD CHECK FOR ERRNO'S HERE
			return ;
		}

		_httpResponse.substr(byteCount);

		if (_httpResponse.empty())
			break ;
	}

	_responseReady = false;
}


void Client::handleRequest()
{
	receiveData();

	// IF PARSER HAS FULL REQUEST
	_httpResponse = httpRequest();
	_responseReady = true;
}

void Client::handleResponse()
{
	if (!_responseReady)
		return ;

	sendData();

	if (_responseReady)
		return;

	if ()
}