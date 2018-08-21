/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:59:27 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/19 14:25:14 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"
#include "factory.hpp"
#include <sstream>

Int8::Int8(void)
{}

Int8::Int8(Int8 &rhs)
{}

Int8::Int8(std::string value): _strValue(value)
{
    this->_Value = stold(value);
}
Int8::~Int8(void)
{}

int Int8::getPrecision( void ) const
{
    return (INT8);
}

eOperandType Int8::getType( void ) const
{
    return (INT8);
}

IOperand const * Int8::operator+( IOperand const & rhs ) const
{
    Factory fac;
    std::string value;

    long long int value1 = static_cast<long long int>(std::stoi(this->toString()));
    if (rhs.getPrecision() > 2)
    {
        if (rhs.getPrecision() > 3)
        {
            long double value2 = static_cast<long double>(std::stold(rhs.toString()));
            long double value3 = value2 + value1;
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
        else
        {
            float value2 = static_cast<float>(std::stof(rhs.toString()));
            float value3 = value2 + value1;
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
    }
    else
    {
        long long int value2 = static_cast<long long int>(std::stoi(rhs.toString()));
        long long int value3 = value2 + value1;
        std::ostringstream ss;
        ss << value3;
        value = ss.str();
    }
    if (this->getPrecision() < rhs.getPrecision())
        return (fac.createOperand(rhs.getType(), value));
    return (fac.createOperand(this->getType(), value));
}

IOperand const * Int8::operator-( IOperand const & rhs ) const
{
    Factory fac;
    std::string value;

    long long int value1 = static_cast<long long int>(std::stoi(this->toString()));
    if (rhs.getPrecision() > 2)
    {
        if (rhs.getPrecision() > 3)
        {
            long double value2 = static_cast<long double>(std::stold(rhs.toString()));
            long double value3 = value2 - value1;
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
        else
        {
            float value2 = static_cast<float>(std::stof(rhs.toString()));
            float value3 = value2 - value1;
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
    }
    else
    {
        long long int value2 = static_cast<long long int>(std::stoi(rhs.toString()));
        long long int value3 = value2 - value1;
        std::ostringstream ss;
        ss << value3;
        value = ss.str();
    }
    if (this->getPrecision() < rhs.getPrecision())
        return (fac.createOperand(rhs.getType(), value));
    return (fac.createOperand(this->getType(), value));
}

IOperand const * Int8::operator*( IOperand const & rhs ) const
{
    Factory fac;
    std::string value;

    long long int value1 = static_cast<long long int>(std::stoi(this->toString()));
    if (rhs.getPrecision() > 2)
    {
        if (rhs.getPrecision() > 3)
        {
            long double value2 = static_cast<long double>(std::stold(rhs.toString()));
            long double value3 = value2 * value1;
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
        else
        {
            float value2 = static_cast<float>(std::stof(rhs.toString()));
            float value3 = value2 * value1;
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
    }
    else
    {
        long long int value2 = static_cast<long long int>(std::stoi(rhs.toString()));
        long long int value3 = value2 * value1;
        std::ostringstream ss;
        ss << value3;
        value = ss.str();
    }
    if (this->getPrecision() < rhs.getPrecision())
        return (fac.createOperand(rhs.getType(), value));
    return (fac.createOperand(this->getType(), value));
}

IOperand const * Int8::operator/( IOperand const & rhs ) const
{
    Factory fac;
    std::string value;

    long long int value1 = static_cast<long long int>(std::stoi(this->toString()));
    if (rhs.getPrecision() > 2)
    {
        if (rhs.getPrecision() > 3)
        {
            long double value2 = static_cast<long double>(std::stold(rhs.toString()));
            long double value3 = value2 / value1;
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
        else
        {
            float value2 = static_cast<float>(std::stof(rhs.toString()));
            float value3 = value2 / value1;
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
    }
    else
    {
        long long int value2 = static_cast<long long int>(std::stoi(rhs.toString()));
        long long int value3 = value2 / value1;
        std::ostringstream ss;
        ss << value3;
        value = ss.str();
    }
    if (this->getPrecision() < rhs.getPrecision())
        return (fac.createOperand(rhs.getType(), value));
    return (fac.createOperand(this->getType(), value));
}

IOperand const * Int8::operator%( IOperand const & rhs ) const
{
    Factory fac;
    std::string value;

    long long int value1 = static_cast<long long int>(std::stoi(this->toString()));
    if (rhs.getPrecision() > 2)
    {
        if (rhs.getPrecision() > 3)
        {
            long double value2 = static_cast<long double>(std::stold(rhs.toString()));
            long double value3 = value1 % static_cast<long long int>(value2);
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
        else
        {
            float value2 = static_cast<float>(std::stof(rhs.toString()));
            float value3 = value1 % static_cast<int>(value2);
            std::ostringstream ss;
            ss << value3;
            value = ss.str();
        }
    }
    else
    {
        long long int value2 = static_cast<long long int>(std::stoi(rhs.toString()));
        long long int value3 = value1 % value2;
        std::ostringstream ss;
        ss << value3;
        value = ss.str();
    }
    if (this->getPrecision() < rhs.getPrecision())
        return (fac.createOperand(rhs.getType(), value));
    return (fac.createOperand(this->getType(), value));
}

std::string const & Int8::toString( void ) const
{
    return (this->_strValue);
}