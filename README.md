# Xtra-Binary-Translator
This project implements a binary translator that converts instructions from a simplified 16-bit RISC-based instruction set into x86-64 assembly code.

# Description

This project implements a binary translator that converts instructions from a simplified 16-bit RISC-based instruction set into x86-64 assembly code. The translator reads binary files containing RISC instructions, decodes them, and outputs their equivalent x86-64 assembly instructions. It handles fundamental operations such as arithmetic (add, sub), data movement (mov), and stack manipulation (push, pop) operations, ensuring that these operations are accurately translated between architectures.

The translation process involves mapping RISC registers to x86-64 registers, as the RISC architecture has 16 general-purpose 16-bit registers, while x86-64 uses 64-bit registers. Each instruction is carefully decoded, and the appropriate x86-64 assembly instructions are generated to match the behavior of the original RISC instructions. This project highlights how different architectures manage data and execute operations.

# Important Note
Since this is a Systems Programming project, the assembler may not be compatible on all systems. It was developed using an SSH connection to Dalhousie University's Faculty of Computer Science's Timberlea server. The project might not run on other platforms without a platform-specific assembler. 

# Acknowledgement
As a part of my Systems Programming course at Dalhousie University, this project includes an assembler and certain code files that were developed by the instructor, Dr. Alex Brodsky (abrodsky@cs.dal.ca).

# Copyright and Ownership
As I am only the author of the program and not the Xtra assembler's code, you may not publish, or use the files that are not written by me in any way without the author's permission. You are allowed to use the part of the project that is mine in accordance with the MIT license shared in the repository.


# License
MIT License

Copyright (c) 2024 Arash Tashakori

Permission is hereby granted, free of charge, to any person obtaining a copy of this software (except the following files: xas.c, xis.h, xreloc.c, and xreloc.h) and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

YOU DO NOT HAVE THE PERMISSION TO USE THE FOLLOWING FILES WITHOUT THE AUTHOR'S PERMISSION: xas.c, xis.h, xreloc.c, and xreloc.h


