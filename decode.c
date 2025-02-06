#include "decode.h"
#include "registers.h"

void decode(instruction toDecode, byte registers[REGISTER_SIZE], address *PC, address *I, byte memory[MEMORY_SIZE]) {
    switch (toDecode / FIRST_DIGIT_DIVISOR) {
    case 0x0:
        break;

    case 0x1:
        *PC = toDecode % FIRST_DIGIT_DIVISOR;
        break;

    case 0x2:
        break;

    case 0x3:
        break;

    case 0x4:
        break;

    case 0x5:
        break;

    case 0x6:
        registers[(toDecode / SECOND_DIGIT_DIVISOR) % 0x10] = toDecode % SECOND_DIGIT_DIVISOR;
        break;

    case 0x7:
        registers[(toDecode / SECOND_DIGIT_DIVISOR) % 0x10] += toDecode % SECOND_DIGIT_DIVISOR;
        break;

    case 0x8:
        break;

    case 0x9:
        break;

    case 0xA:
        *I = toDecode % FIRST_DIGIT_DIVISOR;
        break;

    case 0xB:
        break;

    case 0xC:
        break;

    case 0xD:
        break;

    case 0xE:
        break;

    case 0xF:
        break;
    }
}