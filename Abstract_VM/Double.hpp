/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:19:55 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/13 16:20:58 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include "IOperand.hpp"
# include <iostream>
# include <string>
# include <stdint.h>

class   Double: public IOperand
{
    private:
        int _Type;
        long double _Value;
        std::string _strValue;
    public:
        Double(void);
        Double(Double &rhs);
        Double(std::string value);
        virtual int getPrecision( void ) const; // Precision of the type of the instance
        virtual eOperandType getType( void ) const; // Type of the instance
        virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
        virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo
        virtual std::string const & toString( void ) const; // String representation of the instance
        ~Double(void);
};

#endif