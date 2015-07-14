//

// Author: SiN
// Project: Corewar
// Avaible: https://github.com/Xide/Corewar.git
//

#pragma once

#include <string>
#include "IException.hpp"

class LogError : public IException {
private:

  std::string _what;

public:

  LogError(const std::string&) throw();
  ~LogError() throw() {}

  const char* what() const throw();
};
