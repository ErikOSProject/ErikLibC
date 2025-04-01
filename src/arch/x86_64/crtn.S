/**
 * @file crtn.S
 * @brief C runtime initialization and finalization code for x86_64 architecture.
 *
 * This file contains the assembly code for the C runtime initialization and
 * finalization routines. It is used to set up the environment before the main
 * function is called and to clean up after the main function returns.
 */

.section .init
   popq %rbp
   ret

.section .fini
   popq %rbp
   ret
