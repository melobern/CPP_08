/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:02:08 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/02 09:16:39 by mbernard         ###   ########.fr       */
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
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack(void);
  MutantStack(const MutantStack &src);
  MutantStack <T> &operator=(const MutantStack &src);
  ~MutantStack(void);

  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

  iterator begin(void) { return this->c.begin(); }
  iterator end(void) { return this->c.end(); }
  const_iterator begin(void) const { return this->c.begin(); }
  const_iterator end(void) const { return this->c.end(); }

  reverse_iterator rbegin(void) { return this->c.rbegin(); }
  reverse_iterator rend(void) { return this->c.rend(); }
  const_reverse_iterator rbegin(void) const { return this->c.rbegin(); }
  const_reverse_iterator rend(void) const { return this->c.rend(); }
};

#include "../includes/MutantStack.tpp"

#endif  //  EX02_INCLUDES_MUTANTSTACK_HPP_
