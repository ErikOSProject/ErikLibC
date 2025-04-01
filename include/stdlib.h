/**
 * @file stdlib.h
 * @brief Header file for standard library functions.
 * 
 * This file contains declarations for standard library functions such as
 * malloc, free, and exit. These functions are used for memory
 * management and program termination.
 */

#ifndef _STDLIB_H
#define _STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX 0x7fffffff
#define MB_CUR_MAX 4

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
	int quot;
	int rem;
} div_t;

typedef struct {
	int max;
	int min;
} ldiv_t;

typedef struct {
	long long quot;
	long long rem;
} lldiv_t;

typedef unsigned long size_t;

#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif

void exit(int status);

void *malloc(size_t size);

void free(void *ptr);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _STDLIB_H
