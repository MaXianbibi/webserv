/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req_header.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:36:07 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/11 01:35:53 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/webserv.hpp"

void req::header_creation(const std::string &line)
{
	(void)line;
	// this->header = "Host: " + std::string(inet_ntoa(b.getAddr().sin_addr)) + ":" + std::to_string(ntohs(b.getAddr().sin_port)) + "\r\n";
	this->header = "Host: localhost:" + std::to_string(ntohs(b.getAddr().sin_port)) + "\r\n";
	this->header += "Content-Type: text/html\r\n";
	this->header += "Content-Length: " + std::to_string(this->body.length()) + "\r\n";
	// 				User-Agent
	this->header += "\r\n";
}