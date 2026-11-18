#pragma once


#include <cstdint>
#include <string>
#include <set>

enum AutoIndexSetting {
	NOT_SET,
	ON,
	OFF
};

class LocationConfig {
	private:
		std::set<std::string> _allowedMethods;
		std::string	_path;

		std::string _root;
		std::string _index;

		bool		_uploadEnabled;
		std::string	_uploadPath;

		AutoIndexSetting _autoIndex;

		std::uint16_t	_redirectCode;
		std::string		_redirectTarget;

		
	public:
		const std::set<std::string>& getAllowedMethods() const;
		bool						 isMethodAllowed(const std::string& method) const;

		const std::string&	getPath() const;
		const std::string&	getRoot() const;
		const std::string&	getIndex() const;
		AutoIndexSetting	getAutoIndex() const;
		std::uint16_t		getRedirectCode() const;
		const std::string&	getRedirectTarget() const;
		
		bool				canUpload() const;
		const std::string&	getUploadPath() const;
};
