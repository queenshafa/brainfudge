#include <stdio.h>
#include <stdlib.h>

#define TAPE_SIZE 30000

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("How to use: ./bf <file_name.bf>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", argv[1]);
        return 1;
    }

    char program[TAPE_SIZE] = {0};
    int program_size = 0;

    int ch;
    while ((ch = fgetc(file)) != EOF && program_size < TAPE_SIZE) {
        program[program_size] = (char)ch;
        program_size++;
    }
    fclose(file);

    unsigned char tape[TAPE_SIZE] = {0};
    int ptr = 0;
    int pc = 0;

    while (pc < program_size) {
        switch (program[pc]) {
            case '>': ptr++; if (ptr >= TAPE_SIZE) ptr = 0; break;
            case '<': ptr--; if (ptr < 0) ptr = TAPE_SIZE - 1; break;
            case '+': tape[ptr]++; break;
            case '-': tape[ptr]--; break;
            case '.': putchar(tape[ptr]); break;
            case ',': tape[ptr] = getchar(); break;

            case '[':
                if(tape[ptr] == 0) {
                    int loop_count = 1;
                    while (loop_count > 0) {
                        pc++;
                        if (program[pc] == '[') loop_count++;
                        if (program[pc] == ']') loop_count--;
                    }
                }
                break;

            case ']':
                if(tape[ptr] != 0) {
                    int loop_count = 1;
                    while (loop_count > 0) {
                        pc--;
                        if (program[pc] == ']') loop_count++;
                        if (program[pc] == '[') loop_count--;
                    }
                }
                break;
        }
        pc++;
    }
    
    printf("\n");
    return 0;
}