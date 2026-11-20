#include "../inc/Config.hpp"

Config::Config()
	: _clientMaxBodySize(10 * MB), _autoIndex(false) {

}

Config::Config(const Config& other) {
	*this = other;
}

Config& Config::operator=(const Config& other) {
	if (this != &other) {
		_root = other._root;
		_index = other._index;
		_clientMaxBodySize = other._clientMaxBodySize;
		_autoIndex = other._autoIndex;
	}
	return (*this);
}

Config::~Config() {

}

const std::string& Config::getRoot() const {
	return (_root);
}

const std::string& Config::getIndex() const {
	return (_index);
}

bool Config::getAutoIndex() const {
	return (_autoIndex);
}

std::size_t Config::getClientMaxBodySize() const {
	return (_clientMaxBodySize);
}

void Config::setRoot(const std::string& root) {
	_root = root;
}

void Config::setIndex(const std::string& index) {
	_index = index;
}

void Config::setClientMaxBodySize(std::size_t size) {
	_clientMaxBodySize = size;
}

void Config::setAutoIndex(bool autoIndex) {
	_autoIndex = autoIndex;
}