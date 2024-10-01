/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:02:08 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/01 15:02:52 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_MUTANTSTACK_HPP_
#define EX02_INCLUDES_MUTANTSTACK_HPP_
# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

class MutantStack {
 private:
  const int               _size;
  std::vector<int>        _arr;
  MutantStack(void);

 public:
  explicit MutantStack(const int n);
  MutantStack(const MutantStack &src);
  MutantStack &operator=(const MutantStack &src);
  ~MutantStack();

  void                       addNumber(const int n);
  unsigned int               shortestMutantStack(void);
  unsigned int               longestMutantStack(void);

  template<typename T>
  void addRange(typename T::const_iterator begin, typename T::const_iterator end) {
    size_t len = std::distance(begin, end);

    if (this->_arr.size() + len > static_cast<unsigned int>(this->_size))
      throw spanFullException();
    this->_arr.insert(this->_arr.end(), begin, end);
  }

  void printMutantStack(void);
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

#endif  //  EX02_INCLUDES_MUTANTSTACK_HPP_
