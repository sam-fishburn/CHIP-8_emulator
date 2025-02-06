#include "memory.h"

/**
 * Reads one byte from memory and returns the value of that byte.
 * 
 * @param byteToRead The address of the byte to read from.
 * @param memory The memory to read from.
 * @return The byte at the given address in memory.
 */
byte readByte(address addressToRead, byte memory[MEMORY_SIZE]) {
    if (addressToRead >= MEMORY_SIZE) {
        exit(BUFFER_OVERFLOW);
    } else if (addressToRead < 0) {
        exit(BUFFER_UNDERFLOW);
    } else {
        return memory[addressToRead];
    }
}

/**
 * Writes one byte to memory at a given address.
 * 
 * @param byteToWrite The new byte to write.
 * @param addressToWrite The address to write the new byte to.
 * @param memory The memory to write to.
 */
void writeByte(byte byteToWrite, address addressToWrite, byte memory[MEMORY_SIZE]) {
    if (addressToWrite >= MEMORY_SIZE) {
        exit(BUFFER_OVERFLOW);
    } else if (addressToWrite < 0) {
        exit(BUFFER_UNDERFLOW);
    } else {
        memory[addressToWrite] = byteToWrite;
    }
}