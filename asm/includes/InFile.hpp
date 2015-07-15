//

// Author: SiN
// Project: Corewar
// Avaible: https://github.com/Xide/Corewar.git
//

#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <map>

class InFile {
public:

  typedef int (InFile::*infoFunc)(const std::string&);

public:

  InFile(const std::string&);
  InFile(const InFile&);
  ~InFile();

private:

  bool _fillPgName(const std::string&);
  bool _fillInstr(const std::string&);
  bool _fillVersion(const std::string&);
  bool _fillAuthor(const std::string&);
  bool _fillDate(const std::string&);

public:

  bool assembleFile(bool verbose = false);

private:

  std::string _fileName;
  std::list<std::string> _instr;
  std::string _progName;
  std::string _version;
  std::string _author;
  std::string _date;
  std::map<std::string, infoFunc> _basicFill;
  std::ifstream                   _inStream;
};
