#pragma once

#include <string>
#include <unistd.h>

class Client
{
	private:
		int			_clientSocket;
		std::string _byteBuffer;
		bool 		_isConnected;

	public:
		Client(int clientSocket);
		~Client();

		void receiveData();
		void sendData();
};