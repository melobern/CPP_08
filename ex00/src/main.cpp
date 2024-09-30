/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/27 09:10:39 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>


#include "../includes/easyfind.hpp"

#define CYAN "\033[0;36m"
#define RESET "\033[0m"


int main(int, char **) {
    std::srand(std::time(NULL));
    std::cout << CYAN << "Test with a vector of int" << RESET << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(std::rand() % 10);
    }
    std::cout << "Vector: ";
    for (int i = 0; i < 10; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    try {
        std::cout << "Find 5: " << easyfind(vec, 5) << std::endl;
        std::cout << "Find 10: " << easyfind(vec, 10) << std::endl;
    } catch (notFound &e) {
        std::cout << e.what() << std::endl;
    }
  return 0;
}
