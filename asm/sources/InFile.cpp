#include <sstream>
#include "InFile.hpp"
#include "ParsingError.hpp"

InFile::InFile(const std::string& name) {
  _fileName = name;
  _inStream.open(name.c_str());

  if (!_inStream) throw ParsingError("Error while opening the file");
}

bool
InFile::_fillPgName(const std::string& line) {
  std::stringstream a(line);

  return true;
}

bool
InFile::_fillInstr(const std::string& line) {
  std::stringstream a(line);

  return true;
}

bool
InFile::_fillVersion(const std::string& line) {
  std::stringstream a(line);

  return true;
}

bool
InFile::_fillAuthor(const std::string& line) {
  std::stringstream a(line);

  return true;
}

bool
InFile::_fillDate(const std::string& line) {
  std::stringstream a(line);

  return true;
}
