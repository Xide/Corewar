//
// Author: SiN
// Project: Corewar
// Avaible: https://github.com/Xide/Corewar.git
//

#pragma once

#include <exception>

class IException : public std::exception {
public:
    virtual const char *what() const throw() = 0;
};