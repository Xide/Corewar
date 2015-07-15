#include "LogException.hpp"

LogException::LogException(const std::string &msg) throw() {
  this->_what = msg;
}

LogException::~LogException() throw() { }

const char *
LogException::what() const throw() {
  return this->_what.c_str();
}
