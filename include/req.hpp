/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:03:53 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/11 00:51:23 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQ_HPP
# define REQ_HPP

#include "webserv.hpp"

class req
{
private:
	std::string 		status_line;
	std::string 		header;
	std::string 		body;
	std::ifstream 		file;
	u_int16_t			status_code;
	u_int16_t			methode;

	client				b;

	// status line
	void 					status_line_creation(const std::string &line);

	// pt a supp
	u_int16_t 				parsing_status_line(std::vector<std::string> status_line);
	u_int16_t 				find_methode(std::string methode);
	const std::string		message_status_code(u_int16_t code);

	// header
	void header_creation(const std::string &line);

	// body
	void body_creation(void);
	
	
public:
	std::string		getHttpString(void);
	req(std::string HTTP_REQ, const int fd);
	~req();
};




#endif