/* Copyright 2024 <mbernard>************************************************  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:02:08 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/01 15:02:27 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>
MutantStack<T>::MutantStack(void) {
    return;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) {
    *this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &src) {
    if (this != &src) {
        std::stack<T>::operator=(src);
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
    return;
}