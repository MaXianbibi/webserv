/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req_status_line.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:33:45 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/15 14:14:52 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/webserv.hpp"

req::meth			req::find_methode(std::string &methode)
{
	if (methode == "GET")
		return (&req::getFonc);
	if (methode == "POST")
		return (&req::postFonc);
	if (methode == "PUT")
		return (0);
	if (methode == "DELETE")
		return (0);
	return (0);
}

const std::string req::message_status_code(u_int16_t code)
{
	if (code == OK)
		return (MESSAGE_OK);
	if (code == OK_CREATED)
		return (MESSAGE_OK_CREATED);
	if (code == OK_NO_CONTENT)
		return (MESSAGE_OK_NO_CONTENT);
	if (code == MOVED_TO_NEW_URL)
		return (MESSAGE_MOVED_TO_NEW_URL);
	if (code == NOT_MODIFIED)
		return (MESSAGE_NOT_MODIFIED);
	if (code == BAD_REQUEST)
		return (MESSAGE_BAD_REQUEST);
	if (code == UNAUTHORIZED)
		return (MESSAGE_UNAUTHORIZED);
	if (code == NOT_FOUND)
		return (MESSAGE_NOT_FOUND);
	else
		return (MESSAGE_INTERNAL_SERVER_ERROR);	
}

u_int16_t req::getFonc(std::string &element)
{
	if (element == "/")
		element = "/index.html"; // peut être remplacer par le root index
	this->file.open(element.substr(1));
	this->file_name = element;
	if (!file.is_open())
	{
		this->file_name = "NOT_FOUND.html"; // même chose ici
		return (NOT_FOUND);
	}
	return(OK);
}

u_int16_t req::postFonc(std::string &element)
{
	(void)element;
	
	std::string tmp;
	std::vector<std::string> info;
	tmp = this->http_req.substr(http_req.rfind('\n'));

	info = split(tmp, '&');
	std::cout << "voici les infos obtenue : " << std::endl;
	for (size_t i = 0; i < info.size(); i++)
		std::cout << info[i] << std::endl;
	
	return (OK_NO_CONTENT);
}


u_int16_t req::parsing_status_line(std::vector<std::string> status_line)
{
	if (status_line.size() != 3 || (status_line[2] != "HTTP/1.1\r" && status_line[2] != "HTTP/1.1" ) || (this->methode = find_methode(status_line[0])) == 0)
	{	
		this->file_name = "BAD_REQUEST.html";
		return (BAD_REQUEST);
	}
	return ((this->*methode)(status_line[1]));
}

void req::status_line_creation(const std::string &line)
{
	this->status_code = parsing_status_line(split(line, ' '));
	this->status_line = "HTTP/1.1 " + std::to_string(this->status_code)	 + " " + message_status_code(this->status_code) + "\r\n";
}

