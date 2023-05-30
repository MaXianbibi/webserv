# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    api.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 13:42:46 by loadjou           #+#    #+#              #
#    Updated: 2023/05/24 13:42:47 by loadjou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests

def get_fact(number):
    url = "http://numbersapi.com/{}".format(number)

    r = requests.get(url)
    if r.status_code == 200:
        print(r.text)
    else:
        print("An error occurred, code={}".format(r.status_code))