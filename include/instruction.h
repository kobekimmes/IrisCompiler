
#include "./include.h"

#define INST_SET_SIZE 256

enum INSTRUCTIONS { HALT, NOP, PUSH, POP, ADD, SUB, MULT, DIV, EMIT, JMP, JNE, JE, JLE, JGE, JL, JG, NUM_INST };

typedef u64 (*Instruction)(VM*);

u64 halt(VM* vm);

u64 nop(VM* vm);

u64 push(VM* vm);

u64 pop(VM* vm);

u64 add(VM* vm);

u64 sub(VM* vm);

u64 mult(VM* vm);

u64 div(VM* vm);

u64 emit(VM* vm);

u64 jmp(VM* vm);

Instruction* init_instruction_set();