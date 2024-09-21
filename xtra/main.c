/**
 * @author Arash Tashakori
 */
#include <stdio.h>
#include "translator.h"

/**
 * This program translates a custom assembly code (X format) into x86-64 assembly code
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    //Error handling for the wrong number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    //Open the file and check if it's opened correctly:
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file");
        return 1;
    }

    // Print the Prologue:
    printf(".globl test\n");
    printf("test:\n");
    printf("push %%rbp\n");
    printf("mov %%rsp, %%rbp\n");

    translate_instructions(input_file);

    // Print the Epilogue:
    printf("pop %%rbp\n");
    printf("ret\n");

    fclose(input_file);

    return 0;
}
