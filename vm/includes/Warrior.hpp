#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "Instruction.hpp"

class Warrior {
public:

  Warrior(std::string const& _name,
          std::string const& _author = "",
          std::string const& _version = "",
          std::string const& _date = "");

  const std::string name;
  const std::string author;
  const std::string version;
  const std::string date;
  std::vector<Instruction> source;

  /// followings operators are used by scheduler to
  /// deal with pendings tasks for a warrior
  unsigned operator++();
  unsigned operator++(int);
  unsigned operator--();
  unsigned operator--(int);
  unsigned operator*() const;

private:

  unsigned _pendingTasks;
};

std::ostream& operator<<(std::ostream&,
                         Warrior const&);
