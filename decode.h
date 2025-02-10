#include "fetch.h"
#include "registers.h"

#include <SDL3/SDL.h>

#define FIRST_DIGIT_DIVISOR 0x1000
#define SECOND_DIGIT_DIVISOR 0x100
#define PIXEL_RESIZE 4
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

void decode(instruction toDecode, byte registers[REGISTER_SIZE], address *PC, address *I, byte memory[MEMORY_SIZE], SDL_Renderer *renderer, bool pixels[SCREEN_HEIGHT][SCREEN_WIDTH]);