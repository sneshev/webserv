/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpHandler.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaepark <yaepark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:47:06 by yaepark           #+#    #+#             */
/*   Updated: 2026/11/24 14:22:47 by yaepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_HANDLER_HPP
# define HTTP_HANDLER_HPP

class HttpRequest;
class HttpResponse;
class ServerConfig;

class HttpHandler
{
	private:
	//don't use these
	HttpHandler();
	HttpHandler(const HttpHandler& other);
	HttpHandler& operator=(const HttpHandler& other);

	const ServerConfig& _config;

	public:
	//constructor
	HttpHandler(const ServerConfig& config);

	//deconstructor
	~HttpHandler();

	//member functions
	void handleRequest(const HttpRequest& request, HttpResponse& response); //(2)
	void prepareResponse(const HttpRequest& request, HttpResponse& response) const; //(1)
};

#endif
/* (1) Adds default headers, set connection-related headers, ensure response headers
	are consistent, and prepares the response for serialization*/
/* (2) handles request using one of the allowed methods*/