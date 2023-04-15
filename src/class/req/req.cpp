/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:06:06 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/14 19:19:19 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/webserv.hpp"




std::string		req::getHttpString(void)
{
	return (std::string(this->status_line + this->header + this->body));
}

void req::body_creation(void)
{
	if (!this->file.is_open())
	{
		if (this->status_code == 404)	
			this->file.open("NOT_FOUND.html");
		else if (this->status_code == 400)
			this->file.open("BAD_REQUEST.html");
		if (!this->file.is_open())
			fatal("open");
	}
	this->body.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	file.close();
}

req::req(std::string HTTP_REQ, const int fd) : b(fd)
{
	if (HTTP_REQ.length()  < 1)
		fatal("Bad HTTP REQUEST");
	this->http_req = HTTP_REQ;
	status_line_creation(HTTP_REQ.substr(0, HTTP_REQ.find('\n')));
	if (this->methode == &req::getFonc)
		body_creation();
	header_creation();
}

req::~req()
{
}