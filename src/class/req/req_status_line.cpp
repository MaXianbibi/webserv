/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req_status_line.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:33:45 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/14 00:25:15 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/webserv.hpp"

u_int16_t req::find_methode(std::string methode)
{
	if (methode == "GET")
		return (GET);
	if (methode == "POST")
		return (POST);
	if (methode == "PUT")
		return (PUT);
	if (methode == "DELETE")
		return (DELETE);
	return (0);
}

const std::string req::message_status_code(u_int16_t code)
{
	if (code == OK)
		return (MESSAGE_OK);
	if (code == OK_CREATED)
		return (MESSAGE_OK_CREATED);
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

u_int16_t req::parsing_status_line(std::vector<std::string> status_line)
{
	if (status_line.size() != 3 || (status_line[2] != "HTTP/1.1\r" && status_line[2] != "HTTP/1.1" ) || (this->methode = find_methode(status_line[0])) == 0)
		return (BAD_REQUEST);
	if (status_line[1] == "/")
		status_line[1] = "/index.html"; // peut être remplacer par le root index
	this->file.open(status_line[1].substr(1));
	this->file_name = status_line[1];
	if (!file.is_open())
		return (NOT_FOUND);
	this->file_name = status_line[1];
	return(OK);
}

void req::status_line_creation(const std::string &line)
{
	this->status_code = parsing_status_line(split(line, ' '));
	this->status_line = "HTTP/1.1 " + std::to_string(this->status_code)	 + " " + message_status_code(this->status_code) + "\r\n";
}

