/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listenner.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:44:35 by jmorneau          #+#    #+#             */
/*   Updated: 2023/05/30 17:54:01 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

void listenner::init(u_int32_t port)
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
	if (bind(this->fd_socket, (struct sockaddr *)&this->addr, this->addr_size) < 0)
		fatal("bind");
	if (listen(this->fd_socket, SOMAXCONN) < 0)
		fatal("listen");

	memset(this->fds, 0, MAX_CLIENT);
	this->fds[0].fd = this->getfd();
	this->fds[0].events = POLLIN;
	this->n_fd = 1;
}

listenner::listenner(u_int32_t port)
{
	init(port);
}

listenner::listenner()
{
	init(DEFAULT_PORT);
}

listenner::~listenner()
{}

void listenner::run()
{
	if (poll(fds, this->n_fd, 100) < 0)
		fatal("poll");
	for (u_int16_t i = 0; i < this->n_fd; i++)
	{
		if (fds[i].revents & POLLIN)
		{
			if (i == 0)
			{
				this->fds[this->n_fd].fd = client(*this).getfd();
				this->fds[this->n_fd].events = POLLIN;
				this->n_fd++;
			}
			else
			{
				char buffer[0xffff];
				int res = recv(fds[i].fd, buffer, 0xffff - 1, 0);
				if (res < 0) // pt faire une erreur 500 ici si on spam :/
					continue;
				else if (res == 0)
				{
					close(fds[i].fd);  // close est une fonction autorisée!
					fds[i] = fds[n_fd - 1];
					n_fd--;
				}
				else
				{
					std::cout << RED << "[DEBUG] : \n" << RESET <<  buffer << std::endl;
					req x(std::string(buffer), fds[i].fd);
					if (send(fds[i].fd, x.getHttpString().c_str(), x.getHttpString().length(), 0) < 0)
						continue; // même chose quen haut, pt erreur 500, a voir
				}
			}
		}
	}
}
