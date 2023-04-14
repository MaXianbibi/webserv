/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:48:48 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/13 20:42:51 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

// include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <iostream>
#include <poll.h>
#include <fstream>
#include <vector>

#include "color.hpp"
#include "d_webserv.hpp"
#include "p_webserv.hpp"

// class
#include "socket.hpp"
# include "req.hpp"
#include "server.hpp"

#endif