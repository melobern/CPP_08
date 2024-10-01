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
#define YELLOW "\033[0;93m"
#define RESET "\033[0m"

static void subjectTests(void) {
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

static void exceptionTests(void) {
  std::cout << CYAN "-----------Exception tests-----------" RESET << std::endl;
  std::cout << YELLOW "------------Empty span------------" RESET << std::endl;
  Span sp = Span(5);
  try {
    sp.shortestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << YELLOW "------------One number------------" RESET << std::endl;
  sp.addNumber(5);
  try {
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << YELLOW "----Equal numbers : try longest----" RESET << std::endl;
  sp.addNumber(5);
  try {
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << YELLOW "----Equal numbers : try shortest---" RESET << std::endl;
  sp.addNumber(5);
  sp.addNumber(6);
  try {
      sp.shortestSpan();
  } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
  }
  std::cout << YELLOW "-------------Full span-------------" RESET << std::endl;
  try {
    while (true)
      sp.addNumber(5);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

static std::vector< int > createFollowingNumbersRange(int count) {
	std::vector< int > followers;
	for (int i = 0; i < count; i++)
		followers.push_back(i);
	return (followers);
}

static std::vector< int > createRandomNumbersRange(int count) {
	std::vector< int > randomNumbers;
    srand(time(NULL));
	for (int i = 0; i < count; i++)
		randomNumbers.push_back(rand() % count);
	return (randomNumbers);
}
static void millionTests(void) {
    std::cout << CYAN "------------Million tests-----------" RESET << std::endl;
    std::cout << YELLOW "----------Following range---------" RESET << std::endl;
    Span sp = Span(1000001);
    std::vector<int> range = createFollowingNumbersRange(1000001);
    sp.addRange< std::vector< int > >(range.begin(), range.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << YELLOW "----------Random range----------" RESET << std::endl;
    std::vector<int> randomNumbers = createRandomNumbersRange(1000001);
    Span sp2 = Span(1000001);
    sp2.addRange< std::vector< int > >(randomNumbers.begin(), randomNumbers.end());
    try {
        std::cout << "Longest in random span : " << sp2.longestSpan() << std::endl;
        std::cout << "Shortest in random span : " << sp2.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void) {
  subjectTests();
  exceptionTests();
  millionTests();

  return (0);
}
