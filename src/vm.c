
#include "../include/include.h"

/**

Stack based virtual-machine (a.k.a stack machine)

Two main components;

    1. Data stack - what manages local variables
    2. Instruction stack - what manages the instruction (not very helpful)

    Standard push/pop functionality that is going to rely
    on the linked list data structure

*/ 



enum REGS { R0, R1, R2, R3, R4, R5, R6, R7, R8, 
            F0, F1, F2, F3, F4, F5, F6, F7, F8,
            NUM_REGS
        };


VM* vm_init(Program* p) {
    VM* vm = (VM*) malloc(sizeof(VM));
    if (vm == NULL) {
        return NULL;
    }

    vm->instructions = load_bytecode(p);            // Byte code
    vm->ip = vm->instructions;                      // Instruction pointer, points to the next instruction

    vm->data = (Data*) malloc(STACK_CAP)                   // Data stack pointer
    vm->instruction_set = init_instruction_set();   // Generate instruction array (contains function pointers to different operations)

    vm->registers_f = (f64*) malloc(sizeof(f64) * 8);
    vm->registers_i = (u64*) malloc(sizeof(u64) * 8);

    return vm;
}

void vm_free(VM** vm) {
    free(*vm);
    *vm = NULL;
}

u64* load_bytecode(Program* p) {

}

void execute_bytecode(VM* vm) {

    while (1) {

        u64 inst = *(vm->ip);

        u64* new_ip = vm->instruction_set[inst](vm);

        vm->ip = new_ip;

        if (inst == HALT) {
            break;
        }
    }


}


