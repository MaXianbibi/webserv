/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_webserv.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:24:16 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/10 23:20:02 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_WEBSERV_HPP
# define D_WEBSERV_HPP

#define DEFAULT_PORT 8080	

# define MAX_CLIENT SOMAXCONN

# define MESSAGE_OK 						"OK"
# define MESSAGE_OK_CREATED 				"OK CREATED"
# define MESSAGE_MOVED_TO_NEW_URL 			"MOVED TO NEW URL"
# define MESSAGE_NOT_MODIFIED 				"NOT MODIFIED"
# define MESSAGE_BAD_REQUEST 				"BAD REQUEST"
# define MESSAGE_UNAUTHORIZED 				"UNAUTHORIZED"
# define MESSAGE_NOT_FOUND 					"NOT FOUND"
# define MESSAGE_INTERNAL_SERVER_ERROR		"INTERNAL SERVER ERRROR"

enum		status_code
{
	OK = 200,
	OK_CREATED = 201,
	MOVED_TO_NEW_URL = 301,
	NOT_MODIFIED = 304,
	BAD_REQUEST = 400,
	UNAUTHORIZED = 401,
	NOT_FOUND = 404,
	INTERNAL_SERVER_ERROR = 500
};

enum		HTTP_METHODE
{
	GET = 1,
	POST,
	PUT,
	DELETE
};

#endif