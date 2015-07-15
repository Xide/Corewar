#pragma once

#include <string>
#include "IException.hpp"

class LogException : public IException {
private:
  std::string           _what;
public:
  LogException(std::string const &) throw();
  const char * what() const throw();
  ~LogException() throw();
};
