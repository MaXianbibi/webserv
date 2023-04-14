/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:36:18 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/13 21:31:52 by jmorneau         ###   ########.fr       */
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

class listenner : public c_socket
{
public:
	listenner();
	listenner(u_int32_t port);
	~listenner();
	void run(void);
private:
	pollfd fds[MAX_CLIENT];
	u_int32_t n_fd;
	void init(u_int32_t port);

};

class client : public c_socket
{
public:
	client(listenner &_server);
	client(int fd);
	~client();
private:
};




#endif