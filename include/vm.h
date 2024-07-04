
#ifndef VM_H
#define VM_H

#include "./include.h"

#define INST_SET_SIZE 256
#define byte uint8_t
#define f64 double
#define u64 unsigned long
#define STACK_CAP 20


typedef struct {

    Data* data;
    Instruction* instruction_set;

    u64* ip;
    u64* instructions;

    f64* registers_f;
    u64* registers_i;
    
} VM;

VM* vm_init(Program* p);

void vm_free(VM** vm);

u64* load_bytecode(Program* p);

void execute_bytecode(VM* vm);


#endif // VM_H