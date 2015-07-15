#include "ParsingError.hpp"

ParsingError::ParsingError(const std::string& name) throw() {
  _what = name;
}

const char *
ParsingError::what() const throw() {
  return _what.c_str();
}
