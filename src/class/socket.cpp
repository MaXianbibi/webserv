/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:37:51 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/10 23:52:01 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

c_socket::c_socket() : fd_socket(0)
{
	this->addr_size = sizeof(this->addr);
	memset(&this->addr, 0, this->addr_size);
}

c_socket::~c_socket()
{}

u_int32_t	c_socket::getfd(void)
{
	return (this->fd_socket);
}

sockaddr_in c_socket::getAddr(void)
{
	if (getsockname(this->fd_socket, (struct sockaddr *)&addr, &this->addr_size) < 0)
		fatal("getsockname");
	return (addr);
}