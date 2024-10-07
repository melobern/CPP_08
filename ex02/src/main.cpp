/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/01 09:09:49 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "../includes/MutantStack.hpp"

#define CYAN "\033[0;36m"
#define YELLOW "\033[0;93m"
#define RESET "\033[0m"

static void subjectTests(void) {
  std::cout << YELLOW "------------Subject tests------------" RESET;
  std::cout << std::endl;
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push_back(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  std::cout << std::endl;
}

void emptyTest(void) {
  std::cout << YELLOW << "--------Empty MutantStack test-------" << RESET;
  std::cout << std::endl;
  {
    std::cout << CYAN << "begin & end" << RESET << std::endl;
    MutantStack<int> mstack;
    MutantStack<int>::iterator itBegin = mstack.begin();
    MutantStack<int>::iterator itEnd = mstack.end();
    bool result = itBegin == itEnd;
    std::cout << "Resultat: " << result << std::endl;
  }
  {
    std::cout << CYAN << "rbegin & rend" << RESET << std::endl;
    MutantStack<int> mstack;
    MutantStack<int>::reverse_iterator itBegin = mstack.rbegin();
    MutantStack<int>::reverse_iterator itEnd = mstack.rend();
    bool result = itBegin == itEnd;
    std::cout << "Resultat: " << result << std::endl;
    std::cout << std::endl;
  }
}

void copyTest(void) {
  std::cout << YELLOW << "Copy constructor & copy assignment operator "
            << RESET << std::endl;
  MutantStack<double> mstack;
  mstack.push(1.2);
  mstack.push(42.0);
  std::cout << "Original: " << std::endl;
  MutantStack<double>::const_iterator it = mstack.begin();
  MutantStack<double>::const_iterator ite = mstack.end();
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::cout << std::endl << "Copy constructor: " << std::endl;
  MutantStack<double> copy(mstack);
  MutantStack<double>::const_iterator it2 = copy.begin();
  MutantStack<double>::const_iterator ite2 = copy.end();
  while (it2 != ite2) {
    std::cout << *it2 << std::endl;
    ++it2;
  }
  std::cout << std::endl << "Copy assignment operator: " << std::endl;
  MutantStack<double> copy2;
  copy2 = mstack;
  MutantStack<double>::const_iterator it3 = copy2.begin();
  MutantStack<double>::const_iterator ite3 = copy2.end();
  while (it3 != ite3) {
    std::cout << *it3 << std::endl;
    ++it3;
  }
  std::cout << std::endl;
}

void otherTypesTest(void) {
  std::cout << std::endl;
  std::cout << YELLOW << "Test with other types " << RESET << std::endl;
  {
    std::cout << CYAN << "Elements type: char" << RESET << std::endl;
    MutantStack<char> mstack;
    mstack.push('A');
    mstack.push('B');
    std::cout << "< Before pop > top: " << mstack.top();
    std::cout << " | size: " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "< After pop > top: " << mstack.top();
    std::cout << " | Size: " << mstack.size() << std::endl;
    mstack.push('C');
    mstack.push('D');
    mstack.push('E');
    mstack.push('!');
    MutantStack<char>::iterator it = mstack.begin();
    MutantStack<char>::iterator ite = mstack.end();
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }
  {
    std::cout << CYAN << "Elements type: std::string" << RESET << std::endl;
    MutantStack<std::string> mstack;
    mstack.push("Hello");
    mstack.push("Hey");
    std::cout << "< Before pop > top: " << mstack.top();
    std::cout << " | size: " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "< After pop > top: " << mstack.top();
    std::cout << " | Size: " << mstack.size() << std::endl;
    mstack.push("Salut");
    mstack.push("Chao");
    mstack.push("Hola");
    mstack.push("Guten Tag");
    MutantStack<std::string>::iterator it = mstack.begin();
    MutantStack<std::string>::iterator ite = mstack.end();
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }
}

void iteratorValidityTest(void) {
  std::cout << std::endl << YELLOW << "Iterator test " << RESET << std::endl;
  MutantStack<float> mstack;
  mstack.push(1.1f);
  mstack.push(2.2f);
  mstack.push(3.3f);
  MutantStack<float>::iterator it = mstack.end();
  --it;
  std::cout << *it << std::endl;
  mstack.push(4.4f);
  std::cout << *it << std::endl;
  mstack.pop();
  std::cout << *it << std::endl;
}

int main(void) {
  subjectTests();
  emptyTest();
  copyTest();
  otherTypesTest();
  iteratorValidityTest();

  return (0);
}
