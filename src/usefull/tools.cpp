/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:12:47 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/11 00:30:45 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/webserv.hpp"

std::vector<std::string> split(const std::string &input, char c)
{
 	size_t startPosition = 0;
    size_t spacePosition;

    std::vector<std::string> words;
    while ((spacePosition = input.find(c, startPosition)) != std::string::npos) {
        std::string word = input.substr(startPosition, spacePosition - startPosition);
        words.push_back(word);
        startPosition = spacePosition + 1;
    }
    if (startPosition < input.size()) {
        words.push_back(input.substr(startPosition));
    }
    return (words);
}