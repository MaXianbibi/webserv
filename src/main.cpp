/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:16:52 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/11 01:46:04 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/webserv.hpp"

int main(void)
{
	server a;

	// client b(a);

	struct pollfd fds[MAX_CLIENT];
	int n_fd = 1;


	fds[0].fd = a.getfd();
	fds[0].events = POLLIN;

	while (1)
    {
        int res = poll(fds, n_fd, -1);

        if (res < 0) {
            perror("poll");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < n_fd; i++) {
            if (fds[i].revents & POLLIN) {
                if (i == 0) { // New client connection
                    client b(a);
                    int newfd = b.getfd();

                    fds[n_fd].fd = newfd;
                    fds[n_fd].events = POLLIN;
                    n_fd++;
                } else { // Existing client
                    char buffer[8192] = {0};
                    int n = recv(fds[i].fd, buffer, sizeof(buffer) - 1, 0);
                    if (n < 0)
						fatal("recv");
					else if (n == 0) { // Client disconnected
                        close(fds[i].fd);
                        fds[i] = fds[n_fd - 1];
                        n_fd--;
                    } else {
                        std::cout << RED << "[DEBUG] : \n" << RESET <<  buffer << std::endl;
						req x((std::string(buffer)), fds[i].fd);
						if (send(fds[i].fd, x.getHttpString().c_str(), x.getHttpString().length(), 0) < 0)
							fatal("send");
                    }
                }
            }
        }
    }
}