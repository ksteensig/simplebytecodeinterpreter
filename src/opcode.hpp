#pragma once

namespace dlvm {

typedef enum {
  NOP = 0x00,
  POP = 0x01,
  PUSH_UINT = 0x02,
  PUSH_INT = 0x03,
  PUSH_FLOAT = 0x04,
  PUSH_BOOL = 0x05,
  CAST_UINT = 0x06,
  CAST_INT = 0x07,
  CAST_FLOAT = 0x08,
  CAST_BOOL = 0x09,
  CAST_PTR = 0x0A,
  ADD = 0x10,
  SUB = 0x11,
  MUL = 0x12,
  DIV = 0x13,
  MOD = 0x14,
  AND = 0x20,
  OR = 0x21,
  XOR = 0x22,
  NOT = 0x23,
  LT = 0x24,
  LE = 0x25,
  EQ = 0x26,
  GE = 0x27,
  GT = 0x28,
  CREATE_ARRAY = 0x30,
  ACCESS_ARRAY = 0x31,
  INSERT_ARRAY = 0x32,
  BOX = 0x33,
  UNBOX = 0x34,
  JMPT = 0x40,
  JMP = 0x41,
  RET = 0x42,
  INVOKE_MANAGED = 0x42,
  INVOKE_NATIVE = 0x43,
  SPAWN = 0x50,
  JOIN = 0x51,
  SEND = 0x52,
  RECEIVE = 0x53,
  HALT = 0xFF
} opcode_t;
}
