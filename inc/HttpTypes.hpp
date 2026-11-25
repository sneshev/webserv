/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HttpTypes.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yaepark <yaepark@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 15:31:54 by yaepark       #+#    #+#                 */
/*   Updated: 2026/11/25 14:38:05 by yaepark       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_TYPES_HPP
# define HTTP_TYPES_HPP

# include <string>
# include <vector>
# include <utility>

//!add more status codes https://www.rfc-editor.org/info/rfc9112/#section-3
enum eStatusCode
{
	STATUS_OK = 200,
	STATUS_BAD_REQUEST = 400,
	STATUS_UNAUTHORIZED_ERROR = 401,
	STATUS_FORBIDDEN = 403,
	STATUS_NOT_FOUND = 404,
	STATUS_URI_TOO_LONG = 414,
	STATUS_INTERNAL_SERVER_ERROR = 500,
	STATUS_NOT_IMPLEMENTED = 501
};

using PairString = std::pair<std::string, std::string>;
using VectorPairString = std::vector<std::pair<std::string, std::string>>;

#endif