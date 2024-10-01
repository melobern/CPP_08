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

#include "../includes/Span.hpp"

#define CYAN "\033[0;36m"
#define RESET "\033[0m"
void subjectTests(void) {
  std::cout << CYAN "------------Subject tests------------" RESET << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void exceptionTests(void) {
  std::cout << CYAN "-----------Exception tests-----------" RESET << std::endl;
  Span sp = Span(5);
  try {
    sp.shortestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  sp.addNumber(5);
  try {
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  sp.addNumber(5);
  try {
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
    sp.addNumber(6);
    try {
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    sp.addNumber(5);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
int main(void) {
  subjectTests();
  exceptionTests();
  return (0);
}
