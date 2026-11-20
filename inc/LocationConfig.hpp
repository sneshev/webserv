#pragma once

#include "Config.hpp"

#include <cstdint>
#include <string>
#include <set>

class LocationConfig : public Config {
	private:
		std::set<std::string> _allowedMethods;
		std::string	_path;

		std::string	_uploadPath;

		std::uint16_t	_redirectCode;
		std::string		_redirectTarget;

		
	public:
		LocationConfig();
		LocationConfig(const Config& defaults);
		LocationConfig(const LocationConfig& other);
		LocationConfig& operator=(const LocationConfig& other);
		~LocationConfig();


		const std::set<std::string>& getAllowedMethods() const;
		bool						 isMethodAllowed(const std::string& method) const;

		const std::string&	getPath() const;
		bool				hasRedirectCode() const;
		std::uint16_t		getRedirectCode() const;
		const std::string&	getRedirectTarget() const;
		const std::string&	getUploadPath() const;
		bool				canUpload() const;

		void	setAllowedMethods(const std::set<std::string>& methods);
		void	addAllowedMethod(const std::string& method);
		void	setPath(const std::string& path);
		void	setUploadPath(const std::string& uploadPath);
		void	setRedirectCode(std::uint16_t code);
		void	setRedirectTarget(const std::string& target);
};
