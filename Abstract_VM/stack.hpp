/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:47:48 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/19 11:53:31 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "IOperand.hpp"
# include "factory.hpp"
# include "read.hpp"
# include <vector>
# include <string>
# include <iostream>
# include <sstream>

class Stack
{
    public:
        Stack();
        Stack(Stack &rhs);
        Stack(IOperand const &rhs);
        std::vector<const IOperand *> _Stack;
        void    pushToStack(const IOperand *rhs);
        void    getStackElementValue(std::vector<const IOperand *>&);
        void    addStack(std::vector<const IOperand *> &rhs);
        void    assertTheStack(std::vector<const IOperand *> &rhs);
        void    dumpStack(std::vector<const IOperand *> &rhs);
        void    subStack(std::vector<const IOperand *> &rhs);
        void    mulStack(std::vector<const IOperand *> &rhs);
        void    divStack(std::vector<const IOperand *> &rhs);
        void    modStack(std::vector<const IOperand *> &rhs);
        void    popStack(std::vector<const IOperand *> &rhs);
        void    assertStack();
        void    printStack(char &ascii);

        ~Stack();
};

#endif