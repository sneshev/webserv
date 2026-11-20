/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpResponse.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 16:18:25 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/20 15:55:03 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>

class HttpResponse
{
	public:
	//constructor
	HttpResponse();
	HttpResponse(const HttpResponse& other);
	HttpResponse& operator=(const HttpResponse& other);

	//deconstructor
	~HttpResponse();

	//method functions
	bool build(); //returns is_built_

	//status checkers
	bool isValid();
	bool isBuilt();

	//getters
	std::string& getResponse() const;
	std::map<std::string, std::string>& getHeaders() const;
	//ADD getters

	//setters
	//ADD setters

	private:
	std::string http_version_;
	std::string status_code_;
	std::string reason_phrase_;
	std::map<std::string, std::string> headers_;
	std::string body_;
	std::string complete_reponse_;

	bool is_valid_; //are enough fields filled in to build a valid response
	bool is_built_; //reponse is successfully built
};