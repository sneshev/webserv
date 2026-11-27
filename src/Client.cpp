#include "Client.hpp"

Client::Client(int clientSocket, const ServerConfig& config) : _clientSocket(clientSocket), _config(config)
{}

Client::~Client()
{
	closeSocket();
}

void Client::closeSocket()
{
	if (_clientSocket > 0)
		close(_clientSocket);
}

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
				break ;
			if (errno == EINTR)
				continue ;
		}

		_httpParser.appendUnparsedBuffer(std::string(buf, len));
	}
}

void Client::sendData()
{
	while (1)
	{
		ssize_t byteCount = send();

		if (byteCount == 0)
			closeSocket();

		if (byteCount == ERROR)
		{

		}

		// make substr of httpResponse.front() starting from byteCount

		// if httpResponse.front is empty break
	}

	// delete httpResponse.front
}

void Client::handleRequest()
{
	receiveData();
	parseRequest();

	if (_httpRequest.empty())
		return;

	createResponse();
}

void Client::handleResponse()
{
	if (_httpResponse.empty())
		return;

	sendData();
}

void Client::parseRequest()
{
	eParseResult result = _httpParser.parseRequest();

	switch(result)
	{
		case PARSE_SUCCESS:
		{
			HttpRequest request = _httpParser.getParsedRequest();
			_httpRequest.push_back(request);
			return ;
		}
		case PARSE_ERROR:
		{
			return;
		}
		case PARSE_INCOMPLETE:
		{
			return ;
		}
	}
}

void Client::createResponse()
{
	HttpHandler handler(_config);

	HttpResponse response = handler.handleRequest(_httpRequest.front());
	_httpResponse.push_back(response);
	_httpRequest.pop_front();
}