/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:16:52 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/13 22:21:31 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/webserv.hpp"

int main(void)
{
	std::vector<u_int16_t> port;
	port.push_back(8080);
	port.push_back(8081);
	port.push_back(8082);
	server a(port);

	while (1)
		for (u_int16_t i = 0; i < a.vServer.size(); i++)
			a.vServer[i].run();
}