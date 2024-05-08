
#ifndef VM_H
#define VM_H

#include "./include.h"



typedef struct {

    LinkedList* data;
    Instruction* instruction_set;

    uint8_t* ip;
    uint8_t* instructions;

} VM;

VM* vm_init(Program* p);

void vm_free(VM** vm);

void load_bytecode(Program* p);

void execute_bytecode(VM* vm);


#endif // VM_H