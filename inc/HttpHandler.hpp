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
	//Do not use
	HttpHandler();
	//Do not use
	HttpHandler(const HttpHandler& other);
	//Do not use
	HttpHandler& operator=(const HttpHandler& other);

	const ServerConfig& _config;

	public:
	HttpHandler(const ServerConfig& config);

	~HttpHandler();

	/* Handles request using one of the allowed methods: GET, POST, DELETE
		Adds default headers, set connection-related headers, ensure response headers
		are consistent, and builds the request and serializes it for sending*/
	std::string handleRequest(const HttpRequest& request);
};
#endif
