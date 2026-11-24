#pragma once

#include <string>

class Client
{
	private:
		int			_client;
		std::string _buffer;
		bool 		_connected;

	public:
		Client();
		~Client();

		void receiveData();
		void sendData();
};