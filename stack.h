#include "memory.h"

/** Number of addresses the stack can hold. */
#define STACK_SIZE 16

/** Error code for a stack overflow. */
#define STACK_OVERFLOW 100

/** Error code for a stack underflow. */
#define STACK_UNDERFLOW 101

/**
 * Pops an address from the stack.
 * 
 * @param stack The stack to pop from.
 * @return The address that was popped.
 */
short pop(short stack[STACK_SIZE  + 1]);

/**
 * Pushes an address to the stack.
 * 
 * @param stack The stack to push to.
 * @param address The address to push.
 */
void push(short address, short stack[STACK_SIZE + 1]);