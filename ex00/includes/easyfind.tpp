/* Copyright 2024 <mbernard>*************************************************  #
#                                                                              #
#                                                         :::      ::::::::    #
#    easyfind.tpp                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 08:38:04 by mbernard          #+#    #+#              #
#    Updated: 2024/09/30 11:13:21 by mbernard         ###   ########.fr        #
#                                                                              #
# ****************************************************************************
*/

#include "easyfind.hpp"

#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>
int easyfind(T container, int num) {
    typename T::iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end()) {
        throw notFound();
    }
 return (num);
}

const char* notFound::what() const throw() {
    return (RED "Error: value not found in container." RESET);
}
