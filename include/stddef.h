/**
 * @file stddef.h
 * @brief Standard definitions header file.
 * 
 * This file contains standard definitions for types and macros used in C programming.
 * It includes definitions for NULL, size_t, ptrdiff_t, and the offsetof macro.
 * These definitions are used for pointer arithmetic, memory management, and
 * data structure manipulation.
 */

#ifndef _STDDEF_H
#define _STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define NULL ((void *)0)
#define offsetof(type, member) ((size_t)&((type *)0)->member)

typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef unsigned int max_align_t;

#ifndef __cplusplus
typedef short wchar_t;
#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _STDDEF_H
