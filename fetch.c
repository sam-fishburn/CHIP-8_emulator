/**
 * Reads the current instruction the program counter is pointing to.
 * 
 * @author Sam Fishburn
 * @file fetch.c
 */

#include "fetch.h"

instruction fetch(address *PC, byte memory[MEMORY_SIZE]) {
    if (*PC >= MEMORY_SIZE - 1) {
        // Handle error: PC out of bounds
        exit(1); // Return an invalid instruction or handle appropriately
    }

    byte firstByte = memory[*PC];
    ++*PC;

    byte secondByte = memory[*PC];
    ++*PC;

    return (instruction)(firstByte << 8) | secondByte;
}