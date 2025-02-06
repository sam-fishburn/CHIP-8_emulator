/**
 * Reads the current instruction the program counter is pointing to.
 * 
 * @author Sam Fishburn
 * @file fetch.c
 */

#include "memory.h"

typedef unsigned short instruction;

instruction fetch(address *PC, byte memory[MEMORY_SIZE]);