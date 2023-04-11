/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:44:35 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/10 23:46:26 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"


void server::init(u_int32_t port)
{
	u_int32_t e = 1;
	this->fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_socket == -1)
		fatal("socket");

	if (setsockopt(this->fd_socket, SOL_SOCKET, SO_REUSEADDR, &e, sizeof(e)) < 0)
		fatal("setsockopt");
	this->addr.sin_family = AF_INET;
	this->addr.sin_port = htons(port);
	this->addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(this->fd_socket, (struct sockaddr*)&this->addr, this->addr_size) < 0)
    	fatal("bind");
	if (listen(this->fd_socket, SOMAXCONN) < 0)
        fatal("listen");
}


server::server(u_int32_t port)
{
	init(port);
}

server::server()
{
	init(DEFAULT_PORT);
}

server::~server()
{
	close(fd_socket);
}


