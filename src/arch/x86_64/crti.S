/**
 * @file crti.S
 * @brief C runtime initialization code for x86_64 architecture.
 * 
 * This file contains the initialization and finalization code for the C runtime.
 * It is used to set up the environment before the main function is called and to clean up
 * after the main function returns.
 */

.section .init
.global _init
_init:
   push %rbp
   movq %rsp, %rbp

.section .fini
.global _fini
_fini:
   push %rbp
   movq %rsp, %rbp
