#include "decode.h"
#include "registers.h"
#include "memory.h"

void decode(instruction toDecode, byte registers[REGISTER_SIZE], address *PC, address *I, byte memory[MEMORY_SIZE], SDL_Renderer *renderer, bool pixels[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    switch (toDecode / FIRST_DIGIT_DIVISOR) {
    case 0x0:
        if (toDecode == 0x00E0) {
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
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
        char X = (toDecode / SECOND_DIGIT_DIVISOR) % 0x10;
        char Y = (toDecode / 0x10) % 0x10;
        char N = toDecode % 0x10;

        char xCoord = registers[X] % SCREEN_WIDTH;
        char yCoord= registers[Y] % SCREEN_HEIGHT;
        registers[VF] = 0;

        for (int i = 0; i < N; i++) {
            byte data = memory[*I + i];

            for (int i = 7; i >= 0; i--) {
                char pixel = data / 0b10^i;
                data %= 0b10^i;
                if (pixel != 0) {
                    if (pixels[yCoord][xCoord]) {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        pixels[yCoord][xCoord] = false;
                        registers[VF] = 1;
                    } else {
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                        pixels[yCoord][xCoord] = true;
                    }
                    SDL_FRect rect = {xCoord * PIXEL_RESIZE, yCoord * PIXEL_RESIZE, PIXEL_RESIZE, PIXEL_RESIZE};
                    SDL_RenderFillRect(renderer, &rect);
                }

                xCoord++;
                if (xCoord > SCREEN_WIDTH) {
                    break;
                }
            }

            yCoord++;
            if (yCoord > SCREEN_HEIGHT) {
                break;
            }
        }

        SDL_RenderPresent(renderer);
        
        break;

    case 0xE:
        break;

    case 0xF:
        break;
    }
}