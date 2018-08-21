/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:18:16 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/19 14:24:58 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factory.hpp"

Factory::Factory(void)
{
    // this->__arrayOfFunctionPointersionPointers.push_back(*(createInt8(&value)));
    // findFun[1] = createInt16(value);
    // findFun[2] = createInt32(value);
    // findFun[3] = createDouble(value);
    // findFun[4] = createFloat(value);
    // return (findFun(type));


    // this->funct[0] = &Factory::createInt8;
    // this->funct[1] = &Factory::createInt16;
    // this->funct[2] = &Factory::createInt32;
    // this->funct[3] = &Factory::createFloat;
    // this->funct[4] = &Factory::createDouble;

    // this->__arrayOfFunctionPointersionPointers.push_back(*createInt8(value));
    // this->__arrayOfFunctionPointersionPointers.push_back(*createInt16(value));
    // this->__arrayOfFunctionPointersionPointers.push_back(*createInt32(value));
    // this->__arrayOfFunctionPointersionPointers.push_back(*createDouble(value));
    // this->__arrayOfFunctionPointersionPointers.push_back(*createFloat(value));
}

Factory::Factory(Factory const &rhs)
{}

Factory::~Factory(void)
{}

Factory::Factory(eOperandType type, std::string value)
{}

IOperand const * Factory::createOperand( eOperandType Type, std::string const & value ) const
{
    IOperand const *newOperand;
	
    if (Type == 0)
        newOperand = createInt8(value);
    else if (Type == 1)
        newOperand = createInt16(value);
    else if (Type == 2)
        newOperand = createInt32(value);
    else if (Type == 3)
        newOperand = createFloat(value);
    else if (Type == 4 )
        newOperand = createDouble(value);
    return (newOperand);
}

IOperand const * Factory::createInt8( std::string const & value ) const
{
    IOperand *Int_8 = new Int8(value);
    return (Int_8);
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
    IOperand *Int_16 = new Int16(value);
    return (Int_16);
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
    IOperand *Int_32 = new Int32(value);
    return (Int_32);
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
    IOperand *Double_ = new Double(value);
    return (Double_);
}

IOperand const * Factory::createFloat( std::string const & value ) const
{
    IOperand *Float_ = new Float(value);
    return (Float_);
}