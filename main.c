#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

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

    FILE *rom = fopen("C:/Users/agras/CSProjects/CHIP-8/rom.ch8", "rb");

    byte romByte;
    int idx = 0x200;

    while (fread(&romByte, 1, 1, rom) == 1) {
        memory[idx] = romByte;
        idx++;
    }
    fclose(rom);

    printf("test\n");
    while (run) {
        instruction newInstruction = fetch(&PC, memory);
        decode(newInstruction, registers, &PC, &I, memory, renderer, pixels);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_QUIT) {
                run = false;
            }
        }
    }
    SDL_Quit();

    return 0;
}