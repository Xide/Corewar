//

// Author: SiN
// Project: Corewar
// Avaible: https://github.com/Xide/Corewar.git
//

#pragma once

#include <fstream>
#include <cstdarg>
#include <string>
#include <iomanip>
#include <ctime>
#include "LogError.hpp"

enum level {
  DBG,
  NOTICE,
  WARNING,
  ERROR,
  CRITICAL
};

class Log {
public:

  Log(enum level lvl = NOTICE);
  Log(const Log&);
  ~Log();

public:

  Log& operator=(const Log&);
  bool operator<<(const std::string&);

private:

  std::ofstream _logStream;
  enum level    _lvl;

public:

  bool log(enum level        lvl,
           const std::string format,
           ...);
};
