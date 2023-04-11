/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:36:18 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/11 00:28:54 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SOCKET_HPP
# define SOCKET_HPP

#include "webserv.hpp"

class c_socket
{	
public:
	u_int32_t	getfd(void);
	sockaddr_in getAddr(void);
protected:
	struct sockaddr_in addr;
	socklen_t addr_size;
	int32_t fd_socket;
	c_socket();
	~c_socket();
};

class server : public c_socket
{
public:
	server();
	server(u_int32_t port);
	~server();
private:
	void init(u_int32_t port);

};

class client : public c_socket
{
public:
	client(server &_server);
	client(int fd);
	~client();
private:
};




#endif