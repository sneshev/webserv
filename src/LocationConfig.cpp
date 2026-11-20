#include "../inc/LocationConfig.hpp"

LocationConfig::LocationConfig()
	: Config(), _redirectCode(0) 
{ }

LocationConfig::LocationConfig(const Config& defaults)
	: Config(defaults), _redirectCode(0)
{ }

LocationConfig::~LocationConfig() {

}

LocationConfig& LocationConfig::operator= (const LocationConfig& other) {
	if (this != &other) {
		Config::operator=(other);
		_allowedMethods = other._allowedMethods;
		_path = other._path;
		_uploadPath = other._uploadPath;
		_redirectCode = other._redirectCode;
		_redirectTarget = other._redirectTarget;
	}
	return (*this);
}

LocationConfig::LocationConfig(const LocationConfig& other) 
{
	*this = other;
}


const std::set<std::string>& LocationConfig::getAllowedMethods() const {
	return (_allowedMethods);
}

bool LocationConfig::isMethodAllowed(const std::string& method) const {
	return (_allowedMethods.find(method) != _allowedMethods.end());
}

const std::string& LocationConfig::getPath() const {
	return (_path);
}

bool LocationConfig::hasRedirectCode() const {
	return (_redirectCode != 0);
}

std::uint16_t LocationConfig::getRedirectCode() const {
	return (_redirectCode);
}

const std::string& LocationConfig::getRedirectTarget() const {
	return (_redirectTarget);	
}

bool LocationConfig::canUpload() const {
	return (isMethodAllowed("POST") && !_uploadPath.empty());
}

const std::string& LocationConfig::getUploadPath() const {
	return (_uploadPath);
}


void LocationConfig::setAllowedMethods(const std::set<std::string>& methods) {
	_allowedMethods = methods;
}

void LocationConfig::addAllowedMethod(const std::string& method) {
	_allowedMethods.insert(method);
}

void LocationConfig::setPath(const std::string& path) {
	_path = path;
}

void LocationConfig::setUploadPath(const std::string& uploadPath) {
	_uploadPath = uploadPath;
}

void LocationConfig::setRedirectCode(std::uint16_t code) {
	_redirectCode = code;
}

void LocationConfig::setRedirectTarget(const std::string& target) {
	_redirectTarget = target;
}