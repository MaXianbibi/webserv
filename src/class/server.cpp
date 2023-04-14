/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:42:14 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/13 23:46:07 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

server::server()
{
	listenner tmp;
	vServer.push_back(tmp);
}

server::server(std::vector<u_int16_t> &port_list)
{	
	vServer.reserve(port_list.size());

	for (size_t i = 0; i < vServer.capacity(); i++)
	{
		listenner tmp(port_list.at(i));
		vServer.push_back(tmp);
	}
}

server::~server()
{
	for (size_t i = 0; i < this->vServer.size(); i++)
	{
		std::cout << vServer[i].getfd() << std::endl;
		close(this->vServer[i].getfd());
	}
}
