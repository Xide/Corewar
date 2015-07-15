#pragma once

#include <pthread.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream> // stringstream
#include <iomanip> // setw
#include "unistd.h" // Getpid

// USAGE :

// gLog(enum severity) << "Votre message de log" << std::endl;
// EX:
// gLog(NOTICE) << "Coucou" << std::endl;

enum severity {
  DBG,
  VERBOSE,
  NOTICE,
  WARNING,
  ERROR,
  CRITICAL,
  _SEC_LVLS
};

class Logger
{
public:
#ifdef DEBUG
  Logger(std::string const&, enum severity = DBG);
#else
#ifdef VERBOSE
  Logger(std::string const&, enum severity = VERBOSE);
#else
  Logger(std::string const&, enum severity = NOTICE);
#endif
#endif
  ~Logger();
  void                  setFloor(enum severity);
  Logger&               operator()(enum severity s);
  template<typename T>
  Logger&               operator<<(T const& msg) {
    std::stringstream   ss;

    ss << msg;
    _log << ss.str();
#ifdef DEBUG
    std::cout << ss.str();
#endif
    return *this;
  }
private:
  enum severity         _floor;
  std::ofstream         _log;
};

extern Logger gLog;
