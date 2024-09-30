/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:25:30 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/30 17:05:34 by mbernard         ###   ########.fr       */
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

class Span {
 private:
  const int               _size;
  std::vector<int>        _arr;

 public:
  explicit Span(const int n);
  Span(const Span &src);
  Span &operator=(const Span &src);
  ~Span();

  void                       addNumber(const int n);
  unsigned int               shortestSpan(void);
  unsigned int               longestSpan(void);

  class spanFullException : std::exception {
   public:
    virtual const char* what() const throw();
  }
};

#endif  //  EX02_INCLUDES_EASYFIND_HPP_