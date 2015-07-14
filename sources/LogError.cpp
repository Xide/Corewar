//

// Author: SiN
// Project: Corewar
// Avaible: https://github.com/Xide/Corewar.git
//

#include "LogError.hpp"

LogError::LogError(const std::string& name) throw() {
  _what = name;
}

const char *
LogError::what() const throw() {
  return _what.c_str();
}
