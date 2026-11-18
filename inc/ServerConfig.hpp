#pragma once

#include "LocationConfig.hpp"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include <map>

struct ListenEndpoint {
	std::string		host; //interface
	std::uint16_t	port;
};

class ServerConfig {
	private:
		std::vector<ListenEndpoint> _endpoints;
		std::vector<LocationConfig>	_locations;

		std::string	_root;
		std::size_t	_clientMaxBodySize;

		std::map<std::uint16_t, std::string>	_errorPages; // number and path to file

	public:
		const std::vector<LocationConfig>&	getLocations() const;
		const std::vector<ListenEndpoint>&	getEndpoints() const;
		const std::string&					getRoot() const;
		std::size_t							getClientMaxBodySize() const;
		
		const std::map<std::uint16_t, std::string>&	getErrorPages() const;

};

