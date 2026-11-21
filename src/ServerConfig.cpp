#include "../inc/ServerConfig.hpp"

ServerConfig::ServerConfig() 
	: Config()
{ }

ServerConfig& ServerConfig::operator=(const ServerConfig& other) {
	if (this != &other) {
		Config::operator=(other);
		_locations = other._locations;
		_endpoints = other._endpoints;
		_errorPages = other._errorPages;
	}
	return (*this);
}

ServerConfig::~ServerConfig() {

}

ServerConfig::ServerConfig(const ServerConfig& other) 
{
	*this = other;
}

const std::vector<LocationConfig>& ServerConfig::getLocations() const {
	return (_locations);
}

const std::vector<ListenEndpoint>& ServerConfig::getEndpoints() const {
	return (_endpoints);
}

const std::map<std::uint16_t, std::string>& ServerConfig::getErrorPages() const {
	return (_errorPages);
}

void ServerConfig::addEndpoint(const ListenEndpoint& endpoint) {
	_endpoints.push_back(endpoint);
}

void ServerConfig::addLocation(const LocationConfig& location) {
	_locations.push_back(location);
}

void ServerConfig::setErrorPage(std::uint16_t code, const std::string& path) {
	_errorPages[code] = path;
}

void ServerConfig::print() {
	std::cout << "Printing Server" << "\n";
	std::cout << "endpoints: "; for (std::vector<ListenEndpoint>::iterator it = _endpoints.begin(); it != _endpoints.end(); ++it) {std::cout << it->host << ":" << it->port << " "; }; std::cout << "\n";
	std::cout << "locations: "; for (std::vector<LocationConfig>::iterator it = _locations.begin(); it != _locations.end(); ++it) {std::cout << it->getPath() << " "; }; std::cout << "\n";
	std::cout << "root: " << _root << "\n";
	std::cout << "index: " << (_index.empty() ? "none" : _index) << "\n";
	std::cout << "client max body size: " << _clientMaxBodySize << "\n";
	std::cout << "autoindex: " << (_autoIndex ? "on" : "off") << "\n";
	std::cout << "error pages: "; for (std::map<std::uint16_t, std::string>::iterator it = _errorPages.begin(); it != _errorPages.end(); ++it) {std::cout << it->first << " "; }; std::cout << "\n";
	for (std::vector<LocationConfig>::iterator it = _locations.begin(); it != _locations.end(); ++it) {
		std::cout << "\n";
		it->print();
	}
	std::cout << std::endl;
}