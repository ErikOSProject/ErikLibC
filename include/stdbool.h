/**
 * @file stdbool.h
 * @brief Standard boolean type header file.
 * 
 * This file defines the standard boolean type and its values in C programming.
 * It includes definitions for the boolean type `bool`, and the boolean values
 * `true` and `false`. These definitions are used for logical operations and
 * conditional statements in C programs.
 */

#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define bool _Bool
#define true 1
#define false 0
#define __bool_true_false_are_defined 1

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _STDBOOL_H
