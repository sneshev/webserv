#include "webserv.hpp"
#include "../inc/ServerConfig.hpp"

int main() {
	ServerConfig server;
	server.setRoot("./www");
	server.setIndex("./www/index.html");
	server.setClientMaxBodySize(1 * KB);
	server.setAutoIndex(false);
	server.setErrorPage(404, "./www/error_pages/404.html");
	server.setErrorPage(405, "./www/error_pages/405.html");

	ListenEndpoint e1;
	e1.host = "127.0.0.1";
	e1.port = 8080;

	ListenEndpoint e2;
	e2.host = "127.0.0.1";
	e2.port = 8081;

	LocationConfig www("/");
	www.setRoot("./www");
	www.addAllowedMethod("GET");
	www.setIndex("./www/index.html");
	www.setClientMaxBodySize(1 * KB);
	www.setAutoIndex(false);

	LocationConfig uploads("/uploads");
	uploads.setRoot("./www/uploads");
	uploads.addAllowedMethod("GET");
	uploads.addAllowedMethod("POST");
	uploads.addAllowedMethod("DELETE");
	uploads.setIndex("");
	uploads.setClientMaxBodySize(1 * KB);
	uploads.setAutoIndex(true);
	uploads.setUploadPath("./www/uploads");

	LocationConfig redirect("/nothing");
	redirect.setRedirectCode(301);
	redirect.setRedirectTarget("./www");
	
	server.addEndpoint(e1);
	server.addEndpoint(e2);
	server.addLocation(www);
	server.addLocation(uploads);
	server.addLocation(redirect);

	server.print();
}