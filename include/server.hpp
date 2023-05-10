/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:29:29 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/13 21:45:37 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

class server
{
private:
public:
	std::vector<listenner> vServer;
	server();
	server(std::vector<u_int16_t> &port_list);
	~server();
};
