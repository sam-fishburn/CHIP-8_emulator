/**
 * Reads the current instruction the program counter is pointing to.
 * 
 * @author Sam Fishburn
 * @file fetch.c
 */

#include "fetch.h"

instruction fetch(address *PC, byte memory[MEMORY_SIZE]) {
    byte firstByte = memory[*PC];
    ++*PC;

    byte secondByte = memory[*PC];
    ++*PC;

    return firstByte * 0x100 + secondByte;
}