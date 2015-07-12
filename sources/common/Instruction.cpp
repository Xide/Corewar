#include "Instruction.hpp"

Instruction::Instruction(Opcode   op,
                         Modifier mod,
                         Mode     aM,
                         unsigned aV,
                         Mode     bM,
                         unsigned bV) :
  _opcode(op), _modifier(mod), _aMode(aM), _aValue(aV), _bMode(bM), _bValue(bV) {}

Instruction::Instruction(Instruction const& src) {
  *this = src;
}

Instruction&
Instruction::operator=(Instruction const& src) {
  _opcode   = src._opcode;
  _modifier = src._modifier;
  _aMode    = src._aMode;
  _aValue   = src._aValue;
  _bMode    = src._bMode;
  _bValue   = src._bValue;
  return *this;
}

std::ostream&
Instruction::operator<<(std::ostream& os) const {
  os << "<Instruction " << _opcode << ", " << _modifier
     << ": [A: " << _aMode << ", " << _aValue << "], "
     << ": [B: " << _bMode << ", " << _bValue << "] at " << this << ">";
  return os;
}

std::ostream&
operator<<(std::ostream& os, Instruction const& i) {
  return i << os;
}
