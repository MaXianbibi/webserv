/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req_header.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:36:07 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/14 00:26:25 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/webserv.hpp"

std::string req::cType( void )
{
	std::string tmp = "slaut !";

	size_t pos = this->file_name.find('.');
	if (pos != std::string::npos)
	{
		tmp = this->file_name.substr(pos);
		std::cout << tmp << std::endl;
	}

	return (tmp);
}

void req::header_creation(const std::string &line)
{
	(void)line;
	this->header = "Host: " + std::string(inet_ntoa(b.getAddr().sin_addr)) + ":" + std::to_string(ntohs(b.getAddr().sin_port)) + "\r\n";
	this->header += "Content-Type: text/html\r\n";
	this->header += "Content-Length: " + std::to_string(this->body.length()) + "\r\n";

	cType();
	// 				User-Agent
	this->header += "\r\n";
}