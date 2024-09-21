/**
 * @author Arash Tashakori
 */

#ifndef XTRA_TRANSLATOR_H
#define XTRA_TRANSLATOR_H

#include <stdio.h>

unsigned short convert_to_little_endian(unsigned short value);
void translate_instructions(FILE *input_file);
void find_instruction(unsigned char opcode, unsigned char operand, unsigned short immediate);

#endif //XTRA_TRANSLATOR_H
