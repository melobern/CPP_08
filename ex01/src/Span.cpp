/* Copyright 2024 <mbernard>*************************************************  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:19:44 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/30 17:16:02 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define RED "\033[1;31m"
#define RESET "\033[0m"

Span::Span(void) : _size(0) {
    return;
}

Span::Span(const int n)
            : _size(n) {
    return;
}

Span::Span(const Span &src)
            : _size(src._size) {
    *this = src;
    return;
}

Span& Span::operator=(Span const &src) {
    if (this != &src) {
        this->_arr.assign(src._arr.begin(), src._arr.end());
    }
    return (*this);
}

Span::~Span() {
    return;
}

const char* Span::spanFullException::what() const throw() {
    return (RED "Error : span is full." RESET);
}

void              Span::addNumber(const int n) {
  if (this->_arr.size() == size)
    throw spanFullException();
  this->_arr.push_back(n);
}

unsigned int      Span::shortestSpan(void); {
}

unsigned int      Span::longestSpan(void); {
}

class spanFullException : std::exception {
 public:
  virtual const char* what() const throw();
}
