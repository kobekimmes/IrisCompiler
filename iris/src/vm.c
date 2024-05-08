
#include "../include/include.h"

/**

Stack based virtual-machine (a.k.a stack machine)

Two main components;

    1. Data stack - what manages local variables
    2. Instruction stack - what manages the instruction (not very helpful)

    Standard push/pop functionality that is going to rely
    on the linked list data structure

*/ 

#define INST_SET_SIZE 256

VM* vm_init(Program* p) {
    VM* vm = (VM*) malloc(sizeof(VM));
    if (vm == NULL) {
        return NULL;
    }

    vm->instructions = load_bytecode(p);
    vm->ip = vm->instructions;

    vm->data = list_create(DATA);
    vm->instruction_set = (Instruction*) malloc(INST_SET_SIZE);


    return vm;
}

void vm_free(VM** vm) {
    free(*vm);
    *vm = NULL;
}

void execute_bytecode(VM* vm) {

    while (1) {

        int curr_inst = list_peek_head(vm->instructions)->val;

        switch (curr_inst) {

        }

        list_pop_head(vm->instructions);
    }


}

uint8_t* load_bytecode(Program* p) {

}


