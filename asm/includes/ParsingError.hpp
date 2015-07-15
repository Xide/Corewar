#pragma once

#include <string>
#include "IException.hpp"

class ParsingError : public IException {
private:

  std::string _what;

public:

  ParsingError(const std::string&) throw();
  ~ParsingError() throw() {}

  const char* what() const throw();
};
