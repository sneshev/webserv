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
