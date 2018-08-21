/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:02:58 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/19 15:33:23 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factory.hpp"
#include "read.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "Int8.hpp"
#include "stack.hpp"
#include <string.h>
#include <fstream>
#include "IOperand.hpp"

int     main(int argc, char **argv)
{
    Read    read;
    Stack   stack;
    IOperand const   *Class_A, *Class_B;
    Factory     Fact;
    int         di, num;
    num = 0;
    std::string    str1;
    std::string     s2;
    if (argc < 2)
    {
       while (strcmp(";;", str1.c_str()) != 0)
        {
            std::getline (std::cin, str1);

            s2 = read.findErr(str1);
            if (((strcmp(s2.c_str(), ";;") == 0) || (strcmp(str1.c_str(), ";;") == 0)) || ((strcmp(s2.c_str(), "invalid") == 0) || (strcmp(str1.c_str(), "invalid") == 0)))
                break ;
            
            if (strcmp(read.getCommand().c_str(), "push") == 0)
            {
                stack.pushToStack(Fact.createOperand(read.getEOperandType(), read.getValue()));
            }
            else
            {
                if (strcmp(read.getCommand().c_str(), "add") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.addStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "sub") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.subStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "mul") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.mulStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "div") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    di = stack._Stack.size() - 2;
                    if ((strcmp(stack._Stack[di]->toString().c_str(), "0")) == 0)
                    {
                        std::cout << "\n[Line " << num << "]: " <<  "cannot divide by zero\n";
                        return (0);
                    }
                    stack.divStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "mod") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.modStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "pop") == 0)
                {
                    if (stack._Stack.size() == 0)
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.popStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "assert") == 0)
                {
                    if (stack._Stack.size() == 0)
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    if (((strcmp(stack._Stack[stack._Stack.size() - 1]->toString().c_str(), read.getValue().c_str())) == 0) && ((stack._Stack[stack._Stack.size() -1]->getPrecision() - read.getPrecision()) == 0))
                        stack.assertStack();
                    else
                    {
                        std::cout << "\n[Line " << num << "]: " << "[does not match]\n";
                        return (0);
                    }
                }
                else if (strcmp(read.getCommand().c_str(), "print") == 0)
                {
                    if (stack._Stack.size() == 0)
                    {
                        std::cout << "\nthere's no elements to print from the stack\n";
                        return (0);
                    }
                    if ((stack._Stack[stack._Stack.size() - 1]->getPrecision()) != 0)
                    {
                        std::cout << "\n[Line " << num << "]: " <<  "cannot print values greater than type INT8\n";
                        return (0);
                    }
                    else
                    {
                        int     iPrint = stack._Stack.size() - 1;
                        int     valuePrint;
                        char    asciiPrint;
                        while (iPrint >= 0)
                        {
                            if ((stack._Stack[iPrint]->getPrecision()) != 0)
                            {
                                std::cout << "\n[Line " << iPrint << "]: " <<  "cannot print values greater than type INT8\n";
                                return (0);
                            }
                            valuePrint = std::stoi(stack._Stack[iPrint]->toString());
                            asciiPrint = static_cast<char>(valuePrint);
                            stack.printStack(asciiPrint);
                            iPrint--;
                        }
                    }
                }
                else if (strcmp(read.getCommand().c_str(), "dump") == 0)
                {
                    if (stack._Stack.size() == 0)
                        std::cout << "\n[stack is empty]: please push an element\n";
                    else
                        stack.dumpStack(stack._Stack);
                }
            }
            std::cout << std::endl;
            num++;
        } 
    }
    else
    {
	    std::ifstream infile;
	    infile.open (argv[1]);
        while(!infile.eof())
        {
	        std::getline(infile,str1);

            s2 =read.findErr(str1);
            if (((strcmp(s2.c_str(), "exit") == 0) || (strcmp(str1.c_str(), "exit") == 0)) || ((strcmp(s2.c_str(), "invalid") == 0) || (strcmp(str1.c_str(), "invalid") == 0)))
                break ;
            std::cout << str1 << std::endl;
            if ((strcmp(read.getCommand().c_str(), "push") )== 0)
            {
                stack.pushToStack(Fact.createOperand(read.getEOperandType(), read.getValue()));
            }
            else
            {
                if (strcmp(read.getCommand().c_str(), "add") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.addStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "sub") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.subStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "mul") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.mulStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "div") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    di = stack._Stack.size() - 2;
                    if ((strcmp(stack._Stack[di]->toString().c_str(), "0")) == 0)
                    {
                        std::cout << "\n[Line " << num << "]: " <<  "cannot divide by zero\n";
                        return (0);
                    }
                    stack.divStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "mod") == 0)
                {
                    if ((stack._Stack.size() == 0) || (stack._Stack.size() == 1))
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.modStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "pop") == 0)
                {
                    if (stack._Stack.size() == 0)
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    stack.popStack(stack._Stack);
                }
                else if (strcmp(read.getCommand().c_str(), "assert") == 0)
                {
                    if (stack._Stack.size() == 0)
                    {
                        std::cout << "\nnot enough elements on the stack\n";
                        return (0);
                    }
                    if (((strcmp(stack._Stack[stack._Stack.size() - 1]->toString().c_str(), read.getValue().c_str())) == 0) && ((stack._Stack[stack._Stack.size() -1]->getPrecision() - read.getPrecision()) == 0))
                        stack.assertStack();
                    else
                    {
                        std::cout << "\n[Line " << num << "]: " <<  "[does not match]\n";
                        return (0);
                    }
                }
                else if (strcmp(read.getCommand().c_str(), "print") == 0)
                {
                    if (stack._Stack.size() == 0)
                    {
                        std::cout << "\nthere's no elements to print from the stack\n";
                        return (0);
                    }
                    if ((stack._Stack[stack._Stack.size() - 1]->getPrecision()) != 0)
                    {
                        std::cout << "\n[Line " << num << "]: " <<  "cannot print values greater than type INT8\n";
                        return (0);
                    }
                    else
                    {
                        int     iPrint = stack._Stack.size() - 1;
                        int     valuePrint;
                        char    asciiPrint;
                        while (iPrint >= 0)
                        {
                            if ((stack._Stack[iPrint]->getPrecision()) != 0)
                            {
                                std::cout << "\n[Line " << iPrint << "]: " <<  "cannot print values greater than type INT8\n";
                                return (0);
                            }
                            valuePrint = std::stoi(stack._Stack[iPrint]->toString());
                            asciiPrint = static_cast<char>(valuePrint);
                            stack.printStack(asciiPrint);
                            iPrint--;
                        }
                    }
                }
                else if (strcmp(read.getCommand().c_str(), "dump") == 0)
                {
                    if (stack._Stack.size() == 0)
                        std::cout << "\n[stack is empty]: please push an element\n";
                    else
                        stack.dumpStack(stack._Stack);
                }
            }
            std::cout<< std::endl;
            num++;
        }
	    infile.close();
    }
    return (0);
}