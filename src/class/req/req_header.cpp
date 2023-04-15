/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req_header.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:36:07 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/15 14:12:10 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/webserv.hpp"

std::string req::cType( void )
{
	std::string tmp;

	size_t pos = this->file_name.find('.');
	if (pos == std::string::npos)
		return(std::string("application/octet-stream"));
	tmp = this->file_name.substr(pos);
	for (size_t i = 0; i < mime.size(); i++)
	{
		if (tmp == mime[i].first)
			return (mime[i].second);
	}
	return (std::string("application/octet-stream"));
}

void req::header_creation(void)
{
	this->header = "Host: " + std::string(inet_ntoa(b.getAddr().sin_addr)) + ":" + std::to_string(ntohs(b.getAddr().sin_port)) + "\r\n";
	if (this->methode == &req::getFonc)
	{
		this->header += "Content-Type: " + cType() + "; charset=UTF-8\r\n"; // peut PEUT ËTRE causé un problme (utf-8 etc.)
		this->header += "Content-Length: " + std::to_string(this->body.length()) + "\r\n";
	}

	// 				User-Agent
	this->header += "\r\n";
}