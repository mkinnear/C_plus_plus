/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:48:36 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/13 14:56:51 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

# include "IOperand.hpp"
# include <iostream>
# include <string>
# include <stdint.h>

class   Int8: public IOperand
{
    protected:
        int _Type;
        long double _Value;
        std::string _strValue;
    public:
        Int8(void);
        Int8(Int8 &rhs);
        Int8(std::string value);
        virtual int getPrecision( void ) const; // Precision of the type of the instance
        virtual eOperandType getType( void ) const; // Type of the instance
        virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
        virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo
        virtual std::string const & toString( void ) const; // String representation of the instance
        ~Int8(void);
};

#endif