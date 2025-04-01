/**
 * @file string.c
 * @brief String manipulation functions.
 *  
 * This file contains implementations of basic string manipulation functions
 * such as memset and strlen. These functions are used for copying memory
 * and calculating the length of strings.
 */

#include <string.h>

/**
 * @brief Copies a block of memory from one location to another.
 * 
 * This function copies a block of memory from the source address to the
 * destination address. The memory areas may overlap, and the function
 * handles the overlap correctly.
 * 
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * 
 * @return Pointer to the destination memory area.
 */
void *memset(void *s, int c, size_t n)
{
	unsigned char *p = s;
	while (n--) {
		*p++ = (unsigned char)c;
	}
	return s;
}

/**
 * @brief Calculates the length of a string.
 * 
 * This function calculates the length of a string by counting the number
 * of characters until the null terminator is encountered.
 * 
 * @param s Pointer to the string.
 * 
 * @return Length of the string (excluding the null terminator).
 */
size_t strlen(const char *s)
{
	const char *p = s;
	while (*p) {
		p++;
	}
	return p - s;
}
