typedef enum opcode_e {
    NOP = 0x00,
    ADD = 0x01,
    SUB = 0x02,
    MUL = 0x03,
    DIV = 0x04,
    MOD = 0x05,
    PUSH = 0x06,
    POP = 0x07,
    INSERT_LIST = 0x08,
    SET_LIST = 0x09,
    ACCESS_LIST = 0x0A,
    CALL = 0x0B,
    RET = 0x0C,
    INVOKE = 0x0D,
    LOAD = 0x0E,
    GLOAD = 0x0F,
    AND = 0x10,
    OR = 0x11,
    NOT = 0x12,
    JMP = 0x13,
    JMPF = 0x14,
    JMPT = 0x15,
    PRINT = 0xFE,
    HALT = 0xFF
} opcode_t;

