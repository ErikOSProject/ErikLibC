/**
 * @file crt0.S
 * @brief C runtime startup code for x86_64 architecture.
 * 
 * This file contains the startup code that initializes the C runtime environment
 * and calls the main function.
 */

.section .text

.global _start
_start:
	movq $0, %rbp
	pushq %rbp
	pushq %rbp
	movq %rsp, %rbp

	pushq %rsi
	pushq %rdi

	call init_std
	//call _init

	popq %rdi
	popq %rsi
	call main

	movq %rax, %rdi
	call exit
.size _start, . - _start
