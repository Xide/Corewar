#pragma once

#include <ostream>

typedef enum  eModifier {
  A,
  B,
  AB,
  BA,
  F,
  X,
  I
}             Modifier;

typedef enum  eMode {
  IMMEDIATE,
  DIRECT,
  INDIRECT,
  DECREMENT,
  INCREMENT
}             Mode;

typedef enum  eOpcode {
  DAT,
  MOV,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  JMP,
  JMZ,
  JMN,
  DJN,
  CMP,
  SLT,
  SPL
}             Opcode;


struct Instruction {
  /// Methods

  Instruction(Opcode,
              Modifier,
              Mode,
              unsigned,
              Mode,
              unsigned);
  Instruction(Instruction const&);
  std::ostream& operator<<(std::ostream&) const;
  Instruction & operator=(Instruction const&);

  /// Attributes

  Opcode   _opcode;
  Modifier _modifier;
  Mode     _aMode;
  unsigned _aValue;
  Mode     _bMode;
  unsigned _bValue;
};

std::ostream&   operator<<(std::ostream&, Instruction const&);
