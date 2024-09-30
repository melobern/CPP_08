/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:37:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/30 11:12:50 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_EASYFIND_HPP_
#define EX02_INCLUDES_EASYFIND_HPP_
# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

template<typename T>
int easyfind(T container, int num);

class notFound : std::exception {
  public:
    virtual const char *what() const throw();
};
#include "easyfind.tpp"
#endif  //  EX02_INCLUDES_EASYFIND_HPP_
