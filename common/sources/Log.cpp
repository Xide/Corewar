#include <sys/types.h>
#include <unistd.h>
#include <iomanip>
#include <ctime>
#include "LogException.hpp"
#include "Log.hpp"

Logger          gLog(LOGFILE);

Logger::Logger(std::string const& path, enum severity floor) {
  _log.open(path.c_str(), std::ofstream::out | std::ofstream::app);
  if (!_log.is_open())
    throw LogException("Could not open log file : " + path);
  setFloor(floor);
  (*this)(NOTICE) << "Logger started on file " << path << "\n";
}

Logger::~Logger(void) {
  _log << std::endl << std::endl;
  _log.close();
}

void
Logger::setFloor(enum severity f) { _floor = f; }

Logger&
Logger::operator()(enum severity s) {
    time_t              t;
    struct tm           *ti;
    char                b[80];
    static std::string  severities[_SEC_LVLS] = {"DEBUG", "VERBOSE", "NOTICE",
                                                 "WARNING", "ERROR", "CRITICAL"};
    std::stringstream   ss;

    if (!_log.is_open()) return *this;
    time(&t);
    ti = localtime(&t);
    strftime(b, 80, "%d-%m-%Y %I:%M:%S", ti);
    ss << "[" << getpid() << "]"                                // Expediteur
       << b << " "                                              // Temps
       << std::setw(10) << severities[s].c_str() << " : ";      // Severite
    _log << ss.str();
#ifdef DEBUG
    std::cout << ss.str();
#endif
    return *this;
}

