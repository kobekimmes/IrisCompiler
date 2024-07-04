

#include "../include/include.h"


typedef u64 (*Instruction)(VM*);


u64 halt(VM* vm) {
    return (byte) -1;
}

u64 nop(VM* vm) {
    return (vm->ip)+1;
}

u64 push(VM* vm) {
    if (vm->ip < )
    return (vm->ip)+2;
}

u64 pop(VM* vm) {

    return (vm->ip)+1;
}

u64 add(VM* vm) {

    return (vm->ip)+2;
}

u64 sub(VM* vm) {

    return (vm->ip)+2;
}

u64 mult(VM* vm) {

    return (vm->ip)+2;
}

u64 div(VM* vm) {

    return (vm->ip)+1;
}

u64 emit(VM* vm) {
    
    return (vm->ip)+1;
}

u64 jmp(VM* vm) {
    byte offset = vm->instructions;

    return (vm->ip) + offset;
}

Instruction* init_instruction_set() {
    Instruction* insts = (Instruction*) malloc(sizeof(Instruction) * INST_SET_SIZE);

    if (insts == NULL) {
        return NULL;
    }
    
    insts[HALT] = halt;
    insts[NOP] = nop;
    insts[PUSH] = push;
    insts[POP] = pop;
    insts[ADD] = add;
    insts[SUB] = sub;
    insts[MULT] = mult;
    insts[DIV] = div;
    insts[EMIT] = emit;
    insts[JMP] = jmp;

    return insts;

}
