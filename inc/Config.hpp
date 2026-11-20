#pragma once

#include "configMacros.hpp"

#include <cstdint>
#include <string>
#include <set>

class Config {
	protected:
		std::string _root;
		std::string _index;
		std::size_t	_clientMaxBodySize;

		bool	_autoIndex;

	public:
		Config();
		Config(const Config& other);
		Config& operator=(const Config& other);
		~Config();


		const std::string&	getRoot() const;
		const std::string&	getIndex() const;
		bool				getAutoIndex() const;
		std::size_t			getClientMaxBodySize() const;

		void	setRoot(const std::string& root);
		void	setIndex(const std::string& index);
		void	setClientMaxBodySize(std::size_t size);
		void	setAutoIndex(bool autoIndex);
};
