/**
 * Functions for dealing with the CHIP-8 stack, using arrays.
 * 
 * @author Sam Fishburn
 * @file stack.c
 */

#include "stack.h"

/**
 * Pops an address from the stack.
 * 
 * @param stack The stack to pop from.
 * @return The address that was popped.
 */
address pop(address stack[STACK_SIZE + 1]) {
    stack[STACK_SIZE]--;

    if (stack[STACK_SIZE] < 0) {
        exit(STACK_UNDERFLOW);
    }

    return stack[stack[STACK_SIZE]];
}

/**
 * Pushes an address to the stack.
 * 
 * @param stack The stack to push to.
 * @param newAddress The address to push.
 */
void push(address newAddress, address stack[STACK_SIZE + 1]) {
    if (stack[STACK_SIZE] == STACK_SIZE) {
        exit(STACK_OVERFLOW);
    }

    stack[stack[STACK_SIZE]] = newAddress;

    stack[STACK_SIZE]++;
}