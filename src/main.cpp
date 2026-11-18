#include "webserv.hpp"

int main() {

	HttpRequest hr("HHI");

	std::cout << hr.getParsedLine(hr.METHOD) << std::endl;
}