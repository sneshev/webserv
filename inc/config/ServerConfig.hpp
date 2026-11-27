#pragma once

#include "LocationConfig.hpp"
#include "Config.hpp"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include <map>

struct ListenEndpoint {
	std::string		host; //interface
	std::uint16_t	port;
};

class ServerConfig : public Config {
	private:
		std::vector<LocationConfig>	_locations;
		std::vector<ListenEndpoint> _endpoints;

		std::map<std::uint16_t, std::string>	_errorPages; // number and path to file

	public:
		ServerConfig();
		ServerConfig(const ServerConfig& other);
		ServerConfig& operator=(const ServerConfig& other);
		~ServerConfig();

		const std::vector<LocationConfig>&			getLocations() const;
		const std::vector<ListenEndpoint>&			getEndpoints() const;
		const std::map<std::uint16_t, std::string>&	getErrorPages() const;
		
		const LocationConfig*						findLocation(const std::string& uri) const;

		void	addEndpoint(const ListenEndpoint& endpoint);
		void	addLocation(const LocationConfig& location);
		void	setErrorPage(std::uint16_t code, const std::string& path);

		void	print();
	};