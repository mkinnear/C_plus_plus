/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:52:15 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/13 15:30:08 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_HPP
# define INT16_HPP

# include "IOperand.hpp"
# include <iostream>
# include <string>
# include <stdint.h>

class   Int16: public IOperand
{
    private:
        int _Type;
        long double _Value;
        std::string _strValue;
    public:
        Int16(void);
        Int16(Int16 &rhs);
        Int16(std::string value);
        virtual int getPrecision( void ) const; // Precision of the type of the instance
        virtual eOperandType getType( void ) const; // Type of the instance
        virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
        virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo
        virtual std::string const & toString( void ) const; // String representation of the instance
        ~Int16(void);
};

#endif