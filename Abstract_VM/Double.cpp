/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:14:51 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/13 16:21:11 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"
#include <sstream>
#include "factory.hpp"

Double::Double(void)
{}

Double::Double(Double &rhs)
{}

Double::Double(std::string value): _strValue(value)
{
    this->_Value = stold(value);
}
Double::~Double(void)
{}

int Double::getPrecision( void ) const
{
    return (DOUBLE);
}

eOperandType Double::getType( void ) const
{
    return (DOUBLE);
}

IOperand const * Double::operator+( IOperand const & rhs ) const
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

IOperand const * Double::operator-( IOperand const & rhs ) const
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

IOperand const * Double::operator*( IOperand const & rhs ) const
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

IOperand const * Double::operator/( IOperand const & rhs ) const
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

IOperand const * Double::operator%( IOperand const & rhs ) const
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

std::string const & Double::toString( void ) const
{
    return (this->_strValue);
}