/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:30:56 by mkinnear          #+#    #+#             */
/*   Updated: 2018/08/19 10:58:26 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_HPP
# define READ_HPP

# include <string>
# include <iostream>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <vector>
# include <regex>
# include "IOperand.hpp"

class Read
{
    private:
        std::string _Line;
        std::vector<std::string>    _Instructions;
        std::string _Value;
        std::string _Type;
        eOperandType _eType;
        int          _precision;
        std::string _Command;
    public:
        Read();
        Read(Read &rhs);
        ~Read();
        int         searchOneInstruction(std::string command);
        int         searchCommands(std::string instruction);
        int         ft_strlen(std::string s);
        int         searchValue(std::string value);
        int         findSize(std::string type, std::string value);
        std::string searchSpaces(std::string str);
        std::string findErr(std::string line);
        std::string findInstruction(std::string line);
        std::string findType(std::string line);
        std::string findValue(std::string line);
        std::string getValue();
        std::string getType();
        eOperandType getEOperandType();
        std::string getCommand();
        std::string getLine();
        int         getPrecision();
};

#endif