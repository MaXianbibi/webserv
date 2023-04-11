/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:13:51 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/11 01:36:49 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

client::client(server &_server)
{
	this->fd_socket = accept(_server.getfd(), (struct sockaddr*)&this->addr, &this->addr_size);
	if (fd_socket == -1)
		fatal("accept");
}

client::client(int fd)
{
	this->fd_socket = fd;	
}

client::~client()
{
	// close(fd_socket); // a voir :/
}