/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:22:21 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/13 16:27:15 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"
#include <sstream>
#include "factory.hpp"

Float::Float(void)
{}

Float::Float(Float &rhs)
{}

Float::Float(std::string value): _strValue(value)
{
    this->_Value = stof(value);
}
Float::~Float(void)
{}

int Float::getPrecision( void ) const
{
    return (FLOAT);
}

eOperandType Float::getType( void ) const
{
    return (FLOAT);
}

IOperand const * Float::operator+( IOperand const & rhs ) const
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

IOperand const * Float::operator-( IOperand const & rhs ) const
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

IOperand const * Float::operator*( IOperand const & rhs ) const
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

IOperand const * Float::operator/( IOperand const & rhs ) const
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

IOperand const * Float::operator%( IOperand const & rhs ) const
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

std::string const & Float::toString( void ) const
{
    return (this->_strValue);
}