/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:10:47 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/19 14:53:18 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

Stack::Stack()
{}

Stack::Stack(Stack &rhs)
{}

Stack::Stack(IOperand const &rhs)
{}

Stack::~Stack()
{}

void    Stack::pushToStack(const IOperand *rhs)
{
    this->_Stack.push_back(rhs);
}

void    Stack::dumpStack(std::vector<const IOperand *> &rhs)
{
    int i = rhs.size() - 1;
    while (i >= 0)
    {
        std::cout << std::endl << rhs[i]->toString() << std::endl;
        i--;
    }
}

void    Stack::addStack(std::vector<const IOperand *> &rhs)
{
    Factory fac;
    const IOperand *val;

    val = *(rhs[rhs.size() - 1]) + *(rhs[rhs.size() - 2]);
    rhs.pop_back();
    rhs.pop_back();
        // pushToStack(fac.createOperand(rhs[rhs.size() - 2]->getType(), val->toString()));
    pushToStack(val);
}

void    Stack::subStack(std::vector<const IOperand *> &rhs)
{
    Factory fac;
    const IOperand *val;

    val = *(rhs[rhs.size() - 1]) - *(rhs[rhs.size() - 2]);
    rhs.pop_back();
    rhs.pop_back();
        // pushToStack(fac.createOperand(rhs[rhs.size() - 2]->getType(), val->toString()));
    pushToStack(val);
}

void    Stack::mulStack(std::vector<const IOperand *> &rhs)
{
    Factory fac;
    const IOperand *val;

    val = *(rhs[rhs.size() - 1]) * *(rhs[rhs.size() - 2]);
    rhs.pop_back();
    rhs.pop_back();
        // pushToStack(fac.createOperand(rhs[rhs.size() - 2]->getType(), val->toString()));
    pushToStack(val);
}

void    Stack::divStack(std::vector<const IOperand *> &rhs)
{
    Factory fac;
    const IOperand *val;

    val = *(rhs[rhs.size() - 2]) / *(rhs[rhs.size() - 1]);
    rhs.pop_back();
    rhs.pop_back();
    // pushToStack(fac.createOperand(((rhs[rhs.size() - 2]->getPrecision() > rhs[rhs.size() - 1]->getPrecision()) ? rhs[rhs.size() - 2]->getType() : rhs[rhs.size() - 1]->getType()), val->toString()));
    pushToStack(val);
}

void    Stack::modStack(std::vector<const IOperand *> &rhs)
{
    Factory fac;
    const IOperand *val;

    val = *(rhs[rhs.size() - 1]) % *(rhs[rhs.size() - 2]);
    rhs.pop_back();
    rhs.pop_back();
        // pushToStack(fac.createOperand(rhs[rhs.size() - 2]->getType(), val->toString()));
    pushToStack(val);
}

void    Stack::popStack(std::vector<const IOperand *> &rhs)
{
    rhs.pop_back();
}

void    Stack::assertStack()
{
    std::cout << "[matching]\n";
}
void    Stack::printStack(char &ascii)
{
    std::cout << std::endl <<  ascii << std::endl;
}

// void    Stack::getStackElementValue(std::vector<const IOperand *> &rhs)
// {
//     int i = rhs.size();
//     if (i == 0)
//         std::cout << "the stack element value: " << rhs[0]->toString() << " of type " << rhs[0]->getType() << std::endl;
//     else
//         std::cout << "the stack element value: " << rhs[i - 1]->toString() << " of type " << rhs[i - 1]->getType() << std::endl;
//     // index++;
// }

// {
    // unsigned int i = this->_Stack.size();

    // this->_Stack.push_back(&rhs);
    // std::cout << "the stack size: " << i << std::endl;
// }