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

#include <stddef.h>

typedef struct __locale_struct *locale_t;

void *memccpy(void *restrict dest, const void *restrict src, int c, size_t n);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
void *memcpy(void *restrict dest, const void *restrict src, size_t n);
void *memmem(const void *big, size_t biglen, const void *little,
	     size_t littlelen);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
char *stpcpy(char *restrict dest, const char *restrict src);
char *stpncpy(char *restrict dest, const char *restrict src, size_t n);
char *strcat(char *restrict s1, const char *restrict s2);
char *strchr(const char *s, int c);
int strcmp(const char *s1, const char *s2);
int strcoll(const char *s1, const char *s2);
int strcoll_l(const char *s1, const char *s2, locale_t locale);
char *strcpy(char *restrict dest, const char *restrict src);
size_t strcspn(const char *s, const char *reject);
char *strdup(const char *s);
char *strerror(int errnum);
char *strerror_l(int errnum, locale_t locale);
int strerror_r(int errnum, char *buf, size_t buflen);
size_t strlcat(char *restrict dest, const char *restrict src, size_t size);
size_t strlcpy(char *restrict dest, const char *restrict src, size_t size);
size_t strlen(const char *s);
char *strncat(char *restrict s1, const char *restrict s2, size_t n);
int strncmp(const char *s1, const char *s2, size_t n);
char *strncpy(char *restrict dest, const char *restrict src, size_t n);
char *strndup(const char *s, size_t n);
size_t strnlen(const char *s, size_t maxlen);
char *strpbrk(const char *s, const char *accept);
char *strrchr(const char *s, int c);
// TDOD: char *strsignal(int signum);
size_t strspn(const char *s, const char *accept);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *restrict s, const char *restrict delim);
char *strtok_r(char *restrict s, const char *restrict delim,
	       char **restrict saveptr);
size_t strxfrm(char *restrict dest, const char *restrict src, size_t n);
size_t strxfrm_l(char *restrict dest, const char *restrict src, size_t n,
		 locale_t locale);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _STRING_H
