/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:01:35 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/13 15:49:40 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int16.hpp"
#include "factory.hpp"
#include <sstream>

Int16::Int16(void)
{}

Int16::Int16(Int16 &rhs)
{}

Int16::Int16(std::string value): _strValue(value)
{
    this->_Value = stold(value);
}
Int16::~Int16(void)
{}

int Int16::getPrecision( void ) const
{
    return (INT16);
}

eOperandType Int16::getType( void ) const
{
    return (INT16);
}

IOperand const * Int16::operator+( IOperand const & rhs ) const
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

IOperand const * Int16::operator-( IOperand const & rhs ) const
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

IOperand const * Int16::operator*( IOperand const & rhs ) const
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

IOperand const * Int16::operator/( IOperand const & rhs ) const
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

IOperand const * Int16::operator%( IOperand const & rhs ) const
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

std::string const & Int16::toString( void ) const
{
    return (this->_strValue);
}