#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "registers.h"
#include "fetch.h"

int main() {
    /** 4 KB memory. */
    byte memory[MEMORY_SIZE];

    /** The stack of memory addresses. */
    address stack[STACK_SIZE + 1] = {[STACK_SIZE] = 0};

    /** The program counter; points to the current instruction in memory. */
    address PC;
    
    /** The index register; points to locations in memory. */
    address I;

    /** 16 variable registers, V0-VF. */
    byte registers[REGISTER_SIZE];

    while (true) {
        // FETCHES the instruction
        instruction newInstruction = fetch(&PC, memory);

        // DECODE the instruction to find out what to do

        // EXECUTE the instruction

        // run this loop about 700 times per second
        // this means the program must be manually slowed down
    }
}