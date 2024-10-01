/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:25:30 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/01 09:19:08 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_SPAN_HPP_
#define EX01_INCLUDES_SPAN_HPP_
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
  Span(void);

 public:
  explicit Span(const int n);
  Span(const Span &src);
  Span &operator=(const Span &src);
  ~Span();

  void                       addNumber(const int n);
  unsigned int               shortestSpan(void);
  unsigned int               longestSpan(void);

  template<typename T>
  void addRange(typename T::const_iterator begin, typename T::const_iterator end) {
    size_t len = std::distance(begin, end);

    if (this->_arr.size() + len > static_cast<unsigned int>(this->_size))
      throw spanFullException();
    this->_arr.insert(this->_arr.end(), begin, end);
  }
  
  class spanFullException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class oneNumberException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class noNumberException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class sameNumberException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif  //  EX01_INCLUDES_SPAN_HPP_
