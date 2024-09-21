/**
 * @author Arash Tashakori
 */
#include <stdio.h>
#include "translator.h"

const char *x86_regs[] = {
        "%rax", "%rbx", "%rcx", "%rdx",
        "%rsi", "%rdi", "%r8",  "%r9",
        "%r10", "%r11", "%r12", "%r13",
        "%r14", "%r15", "%rbp", "%rsp"
};

int debug_mode = 0;


/**
 * This method takes a short value (16 bits) assembled in big endian and turns it
 * into little endian
 * @param value big-endian assembled short
 * @return little-endian reassembly of input
 */
unsigned short convert_to_little_endian(unsigned short value) {
    return (value >> 8) | (value << 8); //Convert 16 bit word to big endian
}

/**
 * This method implements the opcode and operand and immediate retrieval and does the main logic
 * of the program
 * @param input_file
 */
void translate_instructions(FILE *input_file) {
    unsigned char opcode;
    unsigned char operand;
    unsigned short immediate;

    //While there are instructions in the file read two at each point (unless extended)
    while (fread(&opcode, 1, 1, input_file) == 1 &&
           fread(&operand, 1, 1, input_file) == 1) {
        // Terminate the search if instruction is 0x0000
        if (opcode == 0x00 && operand == 0x00) {
            break;
        }

        // Check if it's an extended instruction
        if ((opcode & 0xC0) == 0xC0) {
            // Read the immediate value
            if (fread(&immediate, 2, 1, input_file) != 1) {
                printf("Error in reading immediate value.");
                break;
            }

            immediate = convert_to_little_endian(immediate);
        } else { // Not an extended instruction, so no immediate value
            immediate = 0;
        }

        find_instruction(opcode, operand, immediate);
    }
}

/**
 * This method finds the instruction based on a given opcode and operand and immediate value
 * and translates the code if the opcode is valid, and prints error if not.
 * @param opcode - opcode of a X instruction
 * @param operand - operand of a X instruction
 * @param immediate - immediate value if opcode starts with 111
 */
void find_instruction(unsigned char opcode, unsigned char operand, unsigned short immediate) {
    unsigned char regD = operand >> 4;  // extract source register from operand byte
    unsigned char regS = operand & 0x0F;  // extract dest register from operand byte

    //Find and print instruction based on what the opcode is
    switch (opcode) {
        //std - start debugging
        case 0x03:
            debug_mode = 1;
            printf("call debug\n");
            break;
            //cld - clear debugging
        case 0x02:  // cld (clear debug)
            debug_mode = 0;
            break;
            //neg rD (negate register)
        case 0x41:
            printf("neg %s\n", x86_regs[regD]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //not rD - !register
        case 0x42:
            printf("not %s\n", x86_regs[regD]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //push rD - push to program stack
        case 0x43:
            printf("push %s\n", x86_regs[regD]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //pop rD - pop value from stack into register rD.
        case 0x44:
            printf("pop %s\n", x86_regs[regD]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //inc rD - increment rD
        case 0x48:
            printf("inc %s\n", x86_regs[regD]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //dec rD  - decrement rD
        case 0x49:
            printf("dec %s\n", x86_regs[regD]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //add rS, rD
        case 0x81:
            printf("add %s, %s\n", x86_regs[regD], x86_regs[regS]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //sub rS, rD
        case 0x82:
            printf("sub %s, %s\n", x86_regs[regD], x86_regs[regS]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //mul rS, rD
        case 0x83:
            printf("imul %s, %s\n", x86_regs[regD], x86_regs[regS]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //and rS, rD
        case 0x85:
            printf("and %s, %s\n", x86_regs[regD], x86_regs[regS]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //or rS, rD
        case 0x86:
            printf("or %s, %s\n", x86_regs[regD], x86_regs[regS]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //xor rS, rD
        case 0x87:
            printf("xor %s, %s\n", x86_regs[regD], x86_regs[regS]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //test rS1, rS2 (set flag to value of rS1 & rS2 != 0)
        case 0x8A:
            printf("test %s, %s\n", x86_regs[regD], x86_regs[regS]);
            printf("setnz %%r15b\n");
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //cmp rS1, rS2 (set flag to the value of rS1 < rS2)
        case 0x8B:
            printf("cmp %s, %s\n", x86_regs[regD], x86_regs[regS]);
            printf("setg %%r15b\n");
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            //equ rS1, rS2 (set flag to the value of rS1 == rS2)
        case 0x8C:
            printf("cmp %s, %s\n", x86_regs[regD], x86_regs[regS]);
            printf("sete %%r15b\n");
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
            // mov rS, rD  move rS to rD
        case 0x8D:
            printf("mov %s, %s\n", x86_regs[regD], x86_regs[regS]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;

        case 0xE1:  // loadi V, rD
            printf("mov $0x%08X, %s\n", immediate, x86_regs[regD]);
            if (debug_mode) {
                printf("call debug\n");
            }
            break;
        default: //If the opcode is invalid
            printf("Unknown opcode: 0x%02X\n", opcode);
            break;
    }
}
