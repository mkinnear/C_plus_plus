/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:16:07 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/19 13:28:55 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP

# include "IOperand.hpp"
# include "Int8.hpp"
# include "Int16.hpp"
# include "Int32.hpp"
# include "Float.hpp"
# include "Double.hpp"
# include <vector>

class Factory
{
    public:
        Factory(void);
        Factory(Factory const &rhs);
        Factory(eOperandType type, std::string value);
        ~Factory(void);
        // typedef IOperand const*(*functPtrs)(std::string const&);
        // IOperand const* (*funct[5])(eOperandType type, std::string const & value);
        // functPtrs   _arrayOfFunctionPointers[5];
        // Factory(eOperandType type, std::string value);
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
    private:
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;
};

#endif