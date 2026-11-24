#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <print>


#include <poll.h>
//comes with existing struct
struct pollfd
{
	int fd;
	short events;
	short revents;
};



int main()
{
	int serverSocket = 0;
	int clientSocket;

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0)
		return 1;

	sockaddr_in sockadd{};
	sockadd.sin_family = PF_INET;
	sockadd.sin_port = htons(8080);
	sockadd.sin_addr.s_addr = INADDR_ANY;

	if (bind(serverSocket, (sockaddr*)&sockadd, sizeof(sockaddr_in)) == -1)
	{
		close(serverSocket);
		return 1;
	}

	if (listen(serverSocket, SOMAXCONN) == -1)
	{
		close(serverSocket);
		return 1;
	}

	clientSocket = accept(serverSocket, nullptr, nullptr);

	char buffer[10000] = {0};
	read(clientSocket, buffer, 10000);
	std::print("buffer: {}", buffer);
std::string html = R"(
<!DOCTYPE html>
<html>
<head>
    <title>My Server</title>
</head>
<body>
    <h1>Hello from my C++ server!</h1>
    <p>It works!</p>
</body>
</html>
)";

std::string response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n"
    "Content-Length: " + std::to_string(html.size()) + "\r\n"
    "Connection: close\r\n"
    "\r\n" +
    html;

	int i = send(clientSocket, response.c_str(), response.size(), 0);
	std::cout << i;
}