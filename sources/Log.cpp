//
// Author: SiN
// Project: Corewar
// Avaible: https://github.com/Xide/Corewar.git
//

#include <bits/stringfwd.h>
#include <cstdlib>
#include "Log.hpp"

//
// ctor / dtor
//

Log::Log(enum level lvl) {
    _lvl = lvl;
    _logStream.open("corewar.log", std::fstream::out);
    if (!_logStream)
        throw LogError("Can't open the log file");
}

Log::Log(const Log &log) {
    _lvl = log._lvl;
    _logStream.open("../corewar.log", std::fstream::out);
    if (!_logStream)
        throw LogError("Can't open the log file");
}

Log::~Log() {
    if (_logStream)
        _logStream.close();
}

//
// overload
//

Log
&Log::operator=(const Log &log) {
    _lvl = log._lvl;
    _logStream.open("../corewar.log", std::fstream::out);
    if (!_logStream)
        throw LogError("Can't open the log file");
    return *this;
}

bool
Log::operator<<(const std::string &log) {
    _logStream << log << std::endl;
    return true;
}

//
// function
//

bool
Log::log(enum level lvl, const std::string format, ...) {
    va_list     args;
    char        *ptr;
    std::string data;

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    ptr = NULL;
    if (lvl < _lvl)
        return false;
    va_start(args, format);
    vasprintf(&ptr, format.c_str(), args);
    va_end(args);
    data = static_cast<char *>(ptr);
    switch (lvl) {
        case NOTICE:
            _logStream << "[notice] " << std::put_time(&tm, "[%d-%m-%Y %H-%M-%S] ") << data << std::endl;
            break;
        case DEBUG:
            _logStream << "[debug] " << std::put_time(&tm, "[%d-%m-%Y %H-%M-%S] ") << data << std::endl;
            break;
        case WARNING:
            _logStream << "[warning] " << std::put_time(&tm, "[%d-%m-%Y %H-%M-%S] ") << data << std::endl;
            break;
        case ERROR:
            _logStream << "[error] " << std::put_time(&tm, "[%d-%m-%Y %H-%M-%S] ") << data << std::endl;
            break;
        case CRITICAL:
            _logStream << "[critical] " << std::put_time(&tm, "[%d-%m-%Y %H-%M-%S] ") << data << std::endl;
            break;
    }
    free(ptr);
    return true;
}