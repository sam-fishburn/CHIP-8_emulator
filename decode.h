#include "fetch.h"
#include "registers.h"
#include "stack.h"
#include "memory.h"

#include <SDL3/SDL.h>
#include <time.h>

#define FIRST_DIGIT_DIVISOR 0x1000
#define SECOND_DIGIT_DIVISOR 0x100
#define PIXEL_RESIZE 12
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

void decode(instruction toDecode, byte registers[REGISTER_SIZE], address *PC, address *I, address stack[STACK_SIZE + 1], byte memory[MEMORY_SIZE], SDL_Renderer *renderer, bool pixels[SCREEN_HEIGHT][SCREEN_WIDTH]);