/* Copyright 2024 <mbernard>************************************************  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:02:08 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/01 15:02:27 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

#define RED "\033[1;31m"
#define RESET "\033[0m"

MutantStack::MutantStack(void) : _size(0) {
    return;
}

MutantStack::MutantStack(const int n)
            : _size(n) {
    return;
}

MutantStack::MutantStack(const MutantStack &src)
            : _size(src._size) {
    *this = src;
    return;
}

MutantStack& MutantStack::operator=(MutantStack const &src) {
    if (this != &src) {
        this->_arr.assign(src._arr.begin(), src._arr.end());
    }
    return (*this);
}

MutantStack::~MutantStack() {
    return;
}

void              MutantStack::addNumber(const int n) {
  if (this->_arr.size() == static_cast<unsigned int>(this->_size))
    throw spanFullException();
  this->_arr.push_back(n);
}

unsigned int      MutantStack::shortestMutantStack(void) {
  if (this->_arr.size() == 0)
    throw noNumberException();
  if (this->_arr.size() == 1)
    throw oneNumberException();

  std::vector<int> copy = this->_arr;
  std::sort(copy.begin(), copy.end());
  unsigned int shortest = copy.at(1) - copy.at(0);

  for (size_t i = 0; i < copy.size() - 1; ++i) {
    unsigned int tmp = copy.at(i + 1) - copy.at(i);
    if (tmp < shortest)
      shortest = tmp;
    if (shortest == 0) {
      throw sameNumberException();
    }
  }
  return(shortest);
}

unsigned int MutantStack::longestMutantStack(void) {
  if (this->_arr.size() == 0)
    throw noNumberException();
  if (this->_arr.size() == 1)
    throw oneNumberException();
  int min = *std::min_element(this->_arr.begin(), this->_arr.end());
  int max = *std::max_element(this->_arr.begin(), this->_arr.end());
  if (min == max)
    throw sameNumberException();
  return (max - min);
}

const char* MutantStack::spanFullException::what() const throw() {
  return (RED "Error : span is full" RESET);
}

const char* MutantStack::noNumberException::what() const throw() {
  return (RED "Error : span is empty" RESET);
}

const char* MutantStack::oneNumberException::what() const throw() {
  return (RED "Error : only one number in the span" RESET);
}

const char* MutantStack::sameNumberException::what() const throw() {
  return (RED "Error : numbers are equal in the span" RESET);
}

  void MutantStack::printMutantStack(void) {
    for (size_t i = 0; i < this->_arr.size(); ++i) {
      std::cout << this->_arr.at(i) << "\t";
      if (i % 10 == 9 && i != this->_arr.size() - 1)
        std::cout << std::endl;
    }
    std::cout << std::endl;
  }


