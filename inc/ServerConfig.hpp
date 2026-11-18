#pragma once

#include "LocationConfig.hpp"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include <map>

struct ListenEndpoint {
	std::string	host; //interface
	uint16_t	port;
};

class ServerConfig {
	private:
		std::vector<ListenEndpoint> _endpoints;
		std::vector<LocationConfig>	_locations;

		std::string _root;
		size_t		_clientMaxBodySize;

		std::map<int, std::string>	_errorPages; // number and path to file

	public:
		const std::vector<ListenEndpoint>&	getEndpoints() const;
		const std::vector<LocationConfig>&	getLocations() const;
		const std::map<int, std::string>&	getErrorPages() const;
		const std::string&					getRoot() const;
		size_t								getClientMaxBodySize() const;

};

