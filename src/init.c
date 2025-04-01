/**
 * @file init.c
 * @brief Initialization functions for the standard library.
 *  
 * This file contains functions for initializing the standard library and
 * performing system calls. It includes functions for memory management,
 * exiting the program, and handling system calls.
 */

#include <stdlib.h>
#include <stdint.h>

void heap_init(void);

enum syscall_type {
	SYSCALL_EXIT,
	SYSCALL_METHOD,
	SYSCALL_SIGNAL,
	SYSCALL_PUSH,
	SYSCALL_PEEK,
	SYSCALL_POP,
};

/**
 * @brief Initializes the standard library.
 * 
 * This function initializes the standard library by setting up the heap.
 * It should be called before using any other standard library functions.
 */
void init_std(void)
{
	heap_init();
}

void _fini(void);
[[noreturn]] int64_t _syscall(int, void *);

/**
 * @brief Exits the program with the specified status code.
 * 
 * This function terminates the program and returns the specified status code
 * to the operating system. It performs any necessary cleanup before exiting.
 */
void exit(int status)
{
	//_fini();
	_syscall(SYSCALL_EXIT, (void *)(long long)status);
}
