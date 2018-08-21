/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:38:22 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/19 14:37:28 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.hpp"
#include "IOperand.hpp"
#include <limits>

Read::Read()
{ 
    this->_Instructions.push_back("push");
    this->_Instructions.push_back("pop");
    this->_Instructions.push_back("assert");
    this->_Instructions.push_back("add");
    this->_Instructions.push_back("sub");
    this->_Instructions.push_back("mul");
    this->_Instructions.push_back("div");
    this->_Instructions.push_back("mod");
    this->_Instructions.push_back("dump");
    this->_Instructions.push_back("print");
    this->_Instructions.push_back("exit");
    this->_Instructions.push_back("INT8");
    this->_Instructions.push_back("INT16");
    this->_Instructions.push_back("INT32");
    this->_Instructions.push_back("DOUBLE");
    this->_Instructions.push_back("FLOAT");
    }

Read::Read(Read & rhs)
{}

Read::~Read()
{}

std::string Read::getValue()
{
    return (this->_Value);
}

std::string Read::getType()
{
    return (this->_Type);
}

std::string Read::getCommand()
{
    return (this->_Command);
}

std::string Read::getLine()
{
    return (this->_Line);
}

eOperandType Read::getEOperandType()
{
    return (this->_eType);
}

int         Read::getPrecision()
{
    return (this->_precision);
}

int         Read::searchValue(std::string value)
{
    int i = 0;
    while (i < value.size())
    {
        if ((value[0] == '-') && (value[1] >= '0' && value[1] <= '9'))
            i++;
        if ((!(value[i] >= '0' && value[i] <= '9')))
        {
            if (value[i] == '-' && (!(value[i + 1] >= '0' && value[i + 1] <= '9')))
                return (0);
            if (value[i] == ',')
                return (0);
            if ((value[i] == 'e' && value[i + 1] != '-') || (value[i] == 'e' && value[i + 1] != '-'))
                return (0);
            if ((this->_Type == "FLOAT") || (this->_Type == "DOUBLE"))
            {
                if ((value[i] == 'e') || (value[i] == '+') || (value[i] == '-') || (value[i] == '.'))
                    if ((value[i + 1] == 'e') || (value[i + 1] == '+') || (value[i + 1] == '.') || (value[i + 1] == '-'))
                        return (0);
            }
            if ((this->_Type != "FLOAT") || (this->_Type != "DOUBLE"))
            {
                if ((value[i] == '.') || (value[i] == '-'))
                    if ((value[i + 1] == '.') || (value[i + 1] == '-'))
                        return (0);
            }
            if (((this->_Type != "FLOAT") || (this->_Type != "DOUBLE")) && ((value[i] == 'e') || (value[i] == '+')))
            {
                return (0);
            }
        }
        i++;
    }
    return (1);
}

int     Read::ft_strlen(std::string s)
{
    int     i = 0;
    int     j = 0;
    while (i < s.size())
    {
        if (s[i] == ' ')
        {
            i++;
            j++;
        }
        else
            i++;
    }
    if (i == j)
        return (0);
    return (i - j);
}

std::string Read::searchSpaces(std::string str)
{
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    return (str);
}

int   Read::searchCommands(std::string instruction)
{
    int     index = 0;
    int     find = 0;

    while (index < 16)
    {
        if (instruction == this->_Instructions[index])
        {
            find++;
            return (find);
        }
        index++;
    }
    return (0);
}

int         Read::searchOneInstruction(std::string command)
{
    int     i = 0;
    int     j = 0;

    while (i < 16)
    {
        if (command == this->_Instructions[i])
        { 
            if (command == "push" || command == "assert")
                return (0);  
            j++;
            return (j);
        }
        i++;
    }
    return (0);
}

std::string Read::findErr(std::string line)
{
    
    std::string instruction, type, value, s;
    int openBracket, comment, closeBracket, index, et;
    int searchCommand;   
    
    index = 0;
    s.clear();

    line = regex_replace(line, std::regex(" +|\t+"), " ");
    while (line[index] != '\0')
    {
        if (line[index] == ';')
            break ;
        s += line[index++];
    }
    line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");
    if (line[0] == ';')
        return (";");
    if (line == ";")
        return ("[comment]");
    if (line == ";;")
        return (";;");
    this->_Line = s;
    this->_Line = regex_replace(this->_Line, std::regex(" +|\t+"), " ");
    this->_Line = std::regex_replace(this->_Line, std::regex("^ +| +$|( ) +"), "$1");
    if ((searchCommand = searchOneInstruction(this->_Line)) == 1)
    {
        this->_Command = this->_Line;
        if (this->_Line == "exit")
            return ("exit");
        return ("successfull");
    }
    if ((closeBracket = s.find(')')) < (openBracket = s.find('(')))
    {
        std::cout << "the line is invalid\n";
        return ("invalid");
    }
    if ((closeBracket = s.find(')')) == -1)
    {
        std::cout << "the line is invalid\n";
        return ("invalid");
    }
    while (closeBracket++ < s.size())
    {
        if ((s[closeBracket] >= 33) && (s[closeBracket] <= 127))
        {
            std::cout << "invalid line\n";
            return (";;");
        }
    }
    instruction = findInstruction(this->_Line);
    if ((searchCommand = searchCommands(instruction)) == 0)
    {
        std::cout << "[instruction error]\n";
        return (";;");
    }
    this->_Command = instruction;

    type = findType(this->_Line);
    if ((searchCommand = searchCommands(type)) == 0)
    {
        std::cout << "[type error]\n";
        return (";;");
    }
    if (type == "INT8")
    {
        this->_eType = INT8;
        this->_precision = 0;
    }
    else if (type == "INT16")
    {
        this->_eType = INT16;
        this->_precision = 1;
    }
    else if (type == "INT32")
    {
        this->_eType = INT32;
        this->_precision = 2;
    }
    else if (type == "DOUBLE")
    {
        this->_eType = DOUBLE;
        this->_precision = 3;
    }
    else if (type == "FLOAT")
    {
        this->_eType = FLOAT;
        this->_precision = 4;
    }
    this->_Type = type;

    value = findValue(this->_Line);
    if ((searchCommand = searchValue(value)) == 0)
    {
        std::cout << "[value error]\n";
        return (";;");
    }
    if ((searchCommand = findSize(this->_Type, value)) == 0)
    {
        std::cout << "[invalid value]: value out of scope" << std::endl;
        return (";;");
    }
    this->_Value = value;
    return ("[successfull]");
}

int     Read::findSize(std::string type, std::string value)
{
    long double val = stold(value);
    long double val1 = stold(value);
    long double val2 = stold(value);
    long double val3 = stold(value);
    if (this->_Type == "INT8")
    {
        if (val > (std::numeric_limits<int8_t>::max()))
        {
            std::cout << "int8 overflow" << std::endl;
            return (0);
        }
        else if (val < (std::numeric_limits<int8_t>::min()))
        {
            std::cout << "int8 underflow" << std::endl;
            return (0);
        }
    }
    else if (this->_Type == "INT16")
    {
        if (val > (std::numeric_limits<int16_t>::max()))
        {
            std::cout << "int16 overflow" << std::endl;
            return (0);
        }
        else if (val < (std::numeric_limits<int16_t>::min()))
        {
            std::cout << "int16 underflow" << std::endl;
            return (0);
        }
    }
    else if (this->_Type == "INT32")
    {
        if (val1 > (std::numeric_limits<int32_t>::max()))
        {
            std::cout << "int32 overflow" << std::endl;
            return (0);
        }
        else if (val1 < (std::numeric_limits<int32_t>::min()))
        {
            std::cout << "int32 underflow" << std::endl;
            return (0);
        }
    }
    else if (this->_Type == "DOUBLE")
    {
        if (val2 > (std::numeric_limits<double>::max()))
        {
            std::cout << "double overflow" << std::endl;
            return (0);
        }
        else if (val2 < (std::numeric_limits<double>::min()))
        {
            std::cout << "double underflow" << std::endl;
            return (0);
        }
    }
    else if (this->_Type == "FLOAT")
    {
        if (val3 > (std::numeric_limits<float>::max()))
        {
            std::cout << "float overflow" << std::endl;
            return (0);
        }
        else if (val3 < (std::numeric_limits<float>::min()))
        {
            std::cout << "float underflow" << std::endl;
            return (0);
        }
    }
    return (1);
}

std::string    Read::findInstruction(std::string line)
{
    int     index = 0;
    int     end = line.find("int");
    std::string instruction;

    if (end == -1)
        end = line.find("double");
    if (end == -1)
        end = line.find("float");
    if (end == -1)
    if (end == -1)
    {
        std::cout << "invalid line" << std::endl;
        return ("[INVALID INSTRUCTION]");
    }
    while (line[index] != line[end])
    {
        if (line[index] == ' ' && line[index] != line[end])
            index++;
        else
            instruction +=line[index++];
    }
    if((instruction == "push")||(instruction == "assert"))
        return (instruction);
    return ("[to many arguments]");
}

std::string    Read::findType(std::string line)
{
    std::string     type;
    int             index, begin, end;
    line = searchSpaces(line);
    begin = line.find("int");
    if (begin == -1)
        begin = line.find("double");
    if (begin == -1)
        begin = line.find("float");
    if (begin == -1)
    {
        std::cout << "invalid line" << std::endl;
        return ("[INVALID TYPE]");
    }
    end = line.find('(');
    while (begin < end)
    {
        if (line[begin] == ' ')
            begin++;
        else
            type += toupper(line[begin++]);
    }
    return (type);
}  

std::string    Read::findValue(std::string line)
{
    std::string     str, value;
    int             begin, end, distance;
    line = searchSpaces(line);

    begin = line.find('(') + 1;
    end = line.find(')');
    if (begin == end)
    {
        std::cout << "invalid line" << std::endl;
        return ("[invalid number]");
    }
    while (begin < end)
    {
        if (line[begin] == ' ')
            begin++;
        else
            value += line[begin++];
    }
    return (value);
}