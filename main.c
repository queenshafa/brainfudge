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

    unsigned char tape[TAPE_SIZE] = {0};
    int ptr = 0;
    int instruction;
    printf("Fill brainfuck instruction:\n");

    while ((instruction = fgetc(file)) != EOF) {
        putchar(instruction);
    }
    printf("\n");

    fclose(file);
    return 0;
}