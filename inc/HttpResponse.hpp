/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaepark <yaepark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:18:25 by yaepark           #+#    #+#             */
/*   Updated: 2026/11/18 14:22:38 by yaepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include "HttpResponseBuilder.hpp"

class HttpResponse : public HttpResponseBuilder
{
	public:
	//constructor
	HttpResponse();
	HttpResponse(const HttpResponse& other);
	HttpResponse& operator=(const HttpResponse& other);

	//deconstructor
	~HttpResponse();

	//getters
	std::string& getCompleteResponse();
	bool isResponseComplete();
	bool isResponseEmpty();


	private:

};