#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "registers.h"
#include "fetch.h"
#include "decode.h"

int main(int argc, char *argv[]) {
    /** 4 KB memory. */
    byte memory[MEMORY_SIZE] = {
        [FONT_INDEX] = 0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    byte keys[0x10] = {[0x1] = SDL_SCANCODE_1, [0x2] = SDL_SCANCODE_2, [0x3] = SDL_SCANCODE_3, [0xC] = SDL_SCANCODE_4, 
                      [0x4] = SDL_SCANCODE_Q, [0x5] = SDL_SCANCODE_W, [0x6] = SDL_SCANCODE_E, [0xD] = SDL_SCANCODE_R,
                      [0x7] = SDL_SCANCODE_A, [0x8] = SDL_SCANCODE_S, [0x9] = SDL_SCANCODE_D, [0xE] = SDL_SCANCODE_F, 
                      [0xA] = SDL_SCANCODE_Z, [0x0] = SDL_SCANCODE_X, [0xB] = SDL_SCANCODE_C, [0xF] = SDL_SCANCODE_V};

    /** The stack of memory addresses. */
    address stack[STACK_SIZE + 1] = {[STACK_SIZE] = 0};

    /** The program counter; points to the current instruction in memory. */
    address PC = 0x200;
    
    /** The index register; points to locations in memory. */
    address I = 0x0;

    /** 16 variable registers, V0-VF. */
    byte registers[REGISTER_SIZE] = {0};

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_CreateWindowAndRenderer("CHIP-8", SCREEN_WIDTH * PIXEL_RESIZE, SCREEN_HEIGHT * PIXEL_RESIZE, 0, &window, &renderer);
    bool run = true;

    bool pixels[SCREEN_HEIGHT][SCREEN_WIDTH] = {0};

    FILE *rom = fopen("rom.ch8", "rb");

    byte romByte;
    int idx = 0x200;

    byte delayTimer = 0;
    byte soundTimer = 0;
    tick prevTicks = 0;
    tick curTicks;
    int hz;

    while (fread(&romByte, 1, 1, rom) == 1) {
        memory[idx] = romByte;
        idx++;
    }
    fclose(rom);

    while (run) {
        instruction newInstruction = fetch(&PC, memory);
        decode(&curTicks, &prevTicks, &delayTimer, &soundTimer, newInstruction, registers, &PC, &I, stack, memory, renderer, pixels, keys);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                run = false;
            }
        }
        curTicks = SDL_GetTicks();
        hz = (curTicks - prevTicks) / 16;
        if (hz > 0) {
            if (delayTimer > 0) {
                delayTimer--;
            }
            if (soundTimer > 0) {
                soundTimer--;
            }
            prevTicks = curTicks;
        }
    }
    SDL_Quit();

    return 0;
}