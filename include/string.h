/**
 * @file string.h
 * @brief Header file for string manipulation functions.
 * 
 * This file contains declarations for basic string manipulation functions
 * such as memset and strlen. These functions are used for copying memory
 * and calculating the length of strings.
 */

#ifndef _STRING_H
#define _STRING_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef unsigned long size_t;

void *memset(void *s, int c, size_t n);

size_t strlen(const char *s);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _STRING_H
