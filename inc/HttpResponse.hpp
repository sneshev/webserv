/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpResponse.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 16:18:25 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/20 17:42:49 by yaepark       ########   odam.nl         */
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
	bool build(); //returns _isBuilt

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
	std::string httpVersion;
	std::string statusCode;
	std::string reasonPhrase;
	std::map<std::string, std::string> headers;
	std::string body;
	std::string completeReponse;

	bool _isValid; //are enough fields filled in to build a valid response
	bool _isBuilt; //reponse is successfully built
};