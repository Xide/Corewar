#pragma once

#include <stdexcept>

class IException : public std::exception {
public:

  virtual const char* what() const throw() = 0;
};
