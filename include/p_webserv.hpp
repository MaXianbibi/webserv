/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_webserv.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:24:58 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/10 22:19:43 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_WEBSERV_HPP
# define P_WEBSERV_HPP

void fatal(const char *msg);



// ft_split
std::vector<std::string> split(const std::string &input, char c);

#endif