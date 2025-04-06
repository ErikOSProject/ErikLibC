/**
 * @file string.c
 * @brief String manipulation functions.
 *  
 * This file contains implementations of basic string manipulation functions
 * such as memset and strlen. These functions are used for copying memory
 * and calculating the length of strings.
 */

#include <string.h>

#include <errno.h>
#include <stdlib.h>

/**
 * @brief Copies bytes from the source memory area to the destination memory area
 *        until a specified character is encountered or a given number of bytes is copied.
 *
 * @param dest Pointer to the destination memory area where the content is to be copied.
 * @param src Pointer to the source memory area from which the content is to be copied.
 * @param c The character to stop copying at, interpreted as an unsigned char.
 * @param n The maximum number of bytes to copy.
 * @return A pointer to the byte in the destination memory area immediately following
 *         the copied character if the character is found, or NULL if the character is
 *         not found within the first `n` bytes.
 *
 * @note The behavior is undefined if the source and destination memory areas overlap.
 */
void *memccpy(void *restrict dest, const void *restrict src, int c, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;
	while (n--)
		if ((*d++ = *s++) == (unsigned char)c)
			return d;
	return NULL;
}

/**
 * @brief Scans a memory area for the first occurrence of a specified character.
 * 
 * This function searches the first `n` bytes of the memory area pointed to by `s`
 * for the first occurrence of the character `c` (interpreted as an unsigned char).
 * 
 * @param s Pointer to the memory area to be scanned.
 * @param c The character to search for, interpreted as an unsigned char.
 * @param n The number of bytes to scan.
 * @return A pointer to the matching byte, or NULL if the character is not found.
 */
void *memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;
	while (n--) {
		if (*p == (unsigned char)c) {
			return (void *)p;
		}
		p++;
	}
	return NULL;
}

/**
 * @brief Compares two memory areas.
 * 
 * This function compares the first `n` bytes of the memory areas `s1` and `s2`.
 * 
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if the first `n` bytes
 *         of `s1` are found to be less than, equal to, or greater than the first `n` bytes of `s2`.
 */
int memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1 = s1;
	const unsigned char *p2 = s2;
	while (n--) {
		if (*p1 != *p2) {
			return *p1 - *p2;
		}
		p1++;
		p2++;
	}
	return 0;
}

/**
 * @brief Copies a block of memory from one location to another.
 * 
 * This function copies `n` bytes from the memory area `src` to the memory area `dest`.
 * The memory areas must not overlap.
 * 
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area.
 */
void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;
	while (n--) {
		*d++ = *s++;
	}
	return dest;
}

/**
 * @brief Searches for a memory block within another memory block.
 * 
 * This function searches for the first occurrence of the memory block `little`
 * of size `littlelen` within the memory block `big` of size `biglen`.
 * 
 * @param big Pointer to the memory block to search in.
 * @param biglen Size of the memory block to search in.
 * @param little Pointer to the memory block to search for.
 * @param littlelen Size of the memory block to search for.
 * @return A pointer to the beginning of the found memory block, or NULL if not found.
 */
void *memmem(const void *big, size_t biglen, const void *little,
	     size_t littlelen)
{
	if (littlelen == 0) {
		return (void *)big;
	}
	if (biglen < littlelen) {
		return NULL;
	}
	const unsigned char *b = big;
	const unsigned char *l = little;
	for (size_t i = 0; i <= biglen - littlelen; i++) {
		if (memcmp(b + i, l, littlelen) == 0) {
			return (void *)(b + i);
		}
	}
	return NULL;
}

/**
 * @brief Moves a block of memory from one location to another.
 * 
 * This function copies `n` bytes from the memory area `src` to the memory area `dest`.
 * The memory areas may overlap, and the function handles the overlap correctly.
 * 
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area.
 */
void *memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;
	if (d < s) {
		while (n--) {
			*d++ = *s++;
		}
	} else {
		d += n;
		s += n;
		while (n--) {
			*--d = *--s;
		}
	}
	return dest;
}

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
 * @brief Copies a string to a destination buffer, returning a pointer to the null terminator.
 * 
 * This function copies the string pointed to by `src` (including the null terminator)
 * to the buffer pointed to by `dest`. It returns a pointer to the null terminator
 * in the destination buffer.
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @return A pointer to the null terminator in the destination buffer.
 */
char *stpcpy(char *restrict dest, const char *restrict src)
{
	while ((*dest++ = *src++))
		;
	return dest - 1;
}

/**
 * @brief Copies up to `n` characters from a string to a destination buffer, returning a pointer to the null terminator.
 * 
 * This function copies at most `n` characters from the string pointed to by `src`
 * to the buffer pointed to by `dest`. If the null terminator is encountered before
 * `n` characters are copied, the function stops copying and returns a pointer to
 * the null terminator in the destination buffer. If `n` characters are copied
 * without encountering a null terminator, the destination buffer is not null-terminated.
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @param n Maximum number of characters to copy.
 * @return A pointer to the null terminator in the destination buffer, or `dest + n` if no null terminator is found.
 */
char *stpncpy(char *restrict dest, const char *restrict src, size_t n)
{
	while (n && (*dest = *src)) {
		dest++;
		src++;
		n--;
	}
	if (n) {
		while (n--) {
			*dest++ = '\0';
		}
	}
	return dest;
}

/**
 * @brief Concatenates two strings.
 * 
 * This function appends the string pointed to by `s2` to the end of the string
 * pointed to by `s1`. The null terminator of `s1` is overwritten by the first
 * character of `s2`, and a new null terminator is appended at the end of the
 * concatenated string.
 * 
 * @param s1 Pointer to the destination string.
 * @param s2 Pointer to the source string.
 * @return Pointer to the destination string.
 */
char *strcat(char *restrict s1, const char *restrict s2)
{
	char *dest = s1;
	while (*dest) {
		dest++;
	}
	while ((*dest++ = *s2++))
		;
	return s1;
}

/**
 * @brief Locates the first occurrence of a character in a string.
 * 
 * This function searches the string pointed to by `s` for the first occurrence
 * of the character `c` (interpreted as an unsigned char).
 * 
 * @param s Pointer to the string to be searched.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of the character in the string, or NULL if not found.
 */
char *strchr(const char *s, int c)
{
	while (*s) {
		if (*s == (char)c) {
			return (char *)s;
		}
		s++;
	}
	return (c == '\0') ? (char *)s : NULL;
}

/**
 * @brief Compares two strings.
 * 
 * This function compares the strings `s1` and `s2` lexicographically.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @return An integer less than, equal to, or greater than zero if `s1` is found
 *         to be less than, equal to, or greater than `s2`.
 */
int strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

/**
 * @brief Compares two strings using the current locale.
 * 
 * This function compares the strings `s1` and `s2` according to the current locale.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @return An integer less than, equal to, or greater than zero if `s1` is found
 *         to be less than, equal to, or greater than `s2` according to the current locale.
 */
int strcoll(const char *s1, const char *s2)
{
	return strcmp(s1, s2); // Locale-specific comparison not implemented.
}

/**
 * @brief Compares two strings using a specified locale.
 * 
 * This function compares the strings `s1` and `s2` according to the specified locale.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @param locale The locale to use for the comparison.
 * @return An integer less than, equal to, or greater than zero if `s1` is found
 *         to be less than, equal to, or greater than `s2` according to the specified locale.
 */
int strcoll_l(const char *s1, const char *s2, locale_t locale)
{
	(void)locale; // Locale-specific comparison not implemented.
	return strcmp(s1, s2);
}

/**
 * @brief Copies a string to a destination buffer.
 * 
 * This function copies the string pointed to by `src` (including the null terminator)
 * to the buffer pointed to by `dest`.
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @return Pointer to the destination buffer.
 */
char *strcpy(char *restrict dest, const char *restrict src)
{
	char *d = dest;
	while ((*d++ = *src++))
		;
	return dest;
}

/**
 * @brief Calculates the length of the initial segment of a string that does not contain any characters from a reject set.
 * 
 * This function calculates the length of the initial segment of the string `s`
 * that consists entirely of characters not in the string `reject`.
 * 
 * @param s Pointer to the string to be scanned.
 * @param reject Pointer to the string containing the characters to reject.
 * @return The length of the initial segment of `s` that does not contain any characters from `reject`.
 */
size_t strcspn(const char *s, const char *reject)
{
	const char *p = s;
	while (*p) {
		for (const char *r = reject; *r; r++) {
			if (*p == *r) {
				return p - s;
			}
		}
		p++;
	}
	return p - s;
}

/**
 * @brief Duplicates a string.
 * 
 * This function allocates sufficient memory for a copy of the string `s`,
 * copies the string into the allocated memory, and returns a pointer to it.
 * 
 * @param s Pointer to the string to duplicate.
 * @return Pointer to the duplicated string, or NULL if memory allocation fails.
 */
char *strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *dup = malloc(len);
	if (dup) {
		memcpy(dup, s, len);
	}
	return dup;
}

/**
 * @brief Returns a string describing the error code.
 * 
 * This function returns a pointer to a string that describes the error code
 * passed in `errnum`. The string must not be modified by the caller.
 * 
 * @param errnum The error code.
 * @return Pointer to the error description string.
 */
char *strerror(int errnum)
{
	extern const char *const sys_errlist[];
	extern const int sys_nerr;
	if (errnum >= 0 && errnum < sys_nerr) {
		return (char *)sys_errlist[errnum];
	}
	return "Unknown error";
}

/**
 * @brief Returns a string describing the error code using a specified locale.
 * 
 * This function is similar to `strerror`, but uses the specified locale.
 * 
 * @param errnum The error code.
 * @param locale The locale to use for the error description.
 * @return Pointer to the error description string.
 */
char *strerror_l(int errnum, locale_t locale)
{
	(void)locale; // Locale-specific behavior not implemented.
	return strerror(errnum);
}

/**
 * @brief Copies an error message string to a buffer.
 * 
 * This function copies a string describing the error code `errnum` into the
 * buffer `buf` of size `buflen`. If the buffer is too small, the string is
 * truncated and null-terminated.
 * 
 * @param errnum The error code.
 * @param buf Pointer to the buffer to store the error message.
 * @param buflen Size of the buffer.
 * @return 0 on success, or a non-zero value if an error occurs.
 */
int strerror_r(int errnum, char *buf, size_t buflen)
{
	char *msg = strerror(errnum);
	if (strlen(msg) >= buflen) {
		if (buflen > 0) {
			strncpy(buf, msg, buflen - 1);
			buf[buflen - 1] = '\0';
		}
		return ERANGE;
	}
	strcpy(buf, msg);
	return 0;
}

/**
 * @brief Appends a string to a destination buffer with size limit.
 * 
 * This function appends the string `src` to the end of the string `dest`,
 * ensuring that the total length of the resulting string does not exceed
 * `size` (including the null terminator).
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @param size Size of the destination buffer.
 * @return The total length of the string that would have been created if
 *         there were unlimited space (length of `dest` + length of `src`).
 */
size_t strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	size_t dest_len = strlen(dest);
	size_t src_len = strlen(src);
	if (dest_len >= size) {
		return size + src_len;
	}
	size_t copy_len = size - dest_len - 1;
	if (copy_len > src_len) {
		copy_len = src_len;
	}
	memcpy(dest + dest_len, src, copy_len);
	dest[dest_len + copy_len] = '\0';
	return dest_len + src_len;
}

/**
 * @brief Copies a string to a destination buffer with size limit.
 * 
 * This function copies the string `src` to the buffer `dest`, ensuring that
 * the total length of the resulting string does not exceed `size` (including
 * the null terminator).
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @param size Size of the destination buffer.
 * @return The total length of the source string.
 */
size_t strlcpy(char *restrict dest, const char *restrict src, size_t size)
{
	size_t src_len = strlen(src);
	if (size > 0) {
		size_t copy_len = (src_len >= size) ? size - 1 : src_len;
		memcpy(dest, src, copy_len);
		dest[copy_len] = '\0';
	}
	return src_len;
}

/**
 * @brief Calculates the length of a string.
 * 
 * This function calculates the length of a string by counting the number
 * of characters until the null terminator is encountered.
 * 
 * @param s Pointer to the string.
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

/**
 * @brief Appends up to `n` characters from a string to another string.
 * 
 * This function appends at most `n` characters from the string `s2` to the end
 * of the string `s1`. The null terminator of `s1` is overwritten, and a new
 * null terminator is appended at the end of the concatenated string.
 * 
 * @param s1 Pointer to the destination string.
 * @param s2 Pointer to the source string.
 * @param n Maximum number of characters to append.
 * @return Pointer to the destination string.
 */
char *strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char *dest = s1;
	while (*dest) {
		dest++;
	}
	while (n-- && (*dest++ = *s2++))
		;
	if (n == (size_t)-1) {
		*dest = '\0';
	}
	return s1;
}

/**
 * @brief Compares up to `n` characters of two strings.
 * 
 * This function compares at most `n` characters of the strings `s1` and `s2`
 * lexicographically.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @param n Maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if `s1` is found
 *         to be less than, equal to, or greater than `s2`.
 */
int strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && *s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return n == (size_t)-1 ? 0 : (unsigned char)*s1 - (unsigned char)*s2;
}

/**
 * @brief Copies up to `n` characters from a string to a destination buffer.
 * 
 * This function copies at most `n` characters from the string `src` to the
 * buffer `dest`. If the length of `src` is less than `n`, the remainder of
 * `dest` is filled with null bytes.
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @param n Maximum number of characters to copy.
 * @return Pointer to the destination buffer.
 */
char *strncpy(char *restrict dest, const char *restrict src, size_t n)
{
	char *d = dest;
	while (n && (*d++ = *src++)) {
		n--;
	}
	while (n--) {
		*d++ = '\0';
	}
	return dest;
}

/**
 * @brief Duplicates up to `n` characters of a string.
 * 
 * This function allocates sufficient memory for a copy of at most `n`
 * characters of the string `s`, copies the string into the allocated memory,
 * and returns a pointer to it. The resulting string is null-terminated.
 * 
 * @param s Pointer to the string to duplicate.
 * @param n Maximum number of characters to duplicate.
 * @return Pointer to the duplicated string, or NULL if memory allocation fails.
 */
char *strndup(const char *s, size_t n)
{
	size_t len = strnlen(s, n);
	char *dup = malloc(len + 1);
	if (dup) {
		memcpy(dup, s, len);
		dup[len] = '\0';
	}
	return dup;
}

/**
 * @brief Calculates the length of a string, up to a maximum length.
 * 
 * This function calculates the length of the string `s`, but not more than
 * `maxlen` characters.
 * 
 * @param s Pointer to the string.
 * @param maxlen Maximum number of characters to examine.
 * @return The length of the string, or `maxlen` if the null terminator is not found.
 */
size_t strnlen(const char *s, size_t maxlen)
{
	const char *p = s;
	while (maxlen-- && *p) {
		p++;
	}
	return p - s;
}

/**
 * @brief Locates the first occurrence in the string `s` of any character in `accept`.
 * 
 * This function searches the string `s` for the first occurrence of any character
 * in the string `accept`.
 * 
 * @param s Pointer to the string to be searched.
 * @param accept Pointer to the string containing the characters to match.
 * @return A pointer to the first occurrence in `s` of any character in `accept`,
 *         or NULL if no such character is found.
 */
char *strpbrk(const char *s, const char *accept)
{
	while (*s) {
		for (const char *a = accept; *a; a++) {
			if (*s == *a) {
				return (char *)s;
			}
		}
		s++;
	}
	return NULL;
}

/**
 * @brief Locates the last occurrence of a character in a string.
 * 
 * This function searches the string `s` for the last occurrence of the character `c`.
 * 
 * @param s Pointer to the string to be searched.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of the character in the string, or NULL if not found.
 */
char *strrchr(const char *s, int c)
{
	const char *last = NULL;
	do {
		if (*s == (char)c) {
			last = s;
		}
	} while (*s++);
	return (char *)last;
}

/**
 * @brief Calculates the length of the initial segment of a string that consists only of characters from an accept set.
 * 
 * This function calculates the length of the initial segment of the string `s`
 * that consists entirely of characters in the string `accept`.
 * 
 * @param s Pointer to the string to be scanned.
 * @param accept Pointer to the string containing the characters to match.
 * @return The length of the initial segment of `s` that consists only of characters from `accept`.
 */
size_t strspn(const char *s, const char *accept)
{
	const char *p = s;
	while (*p) {
		int found = 0;
		for (const char *a = accept; *a; a++) {
			if (*p == *a) {
				found = 1;
				break;
			}
		}
		if (!found) {
			break;
		}
		p++;
	}
	return p - s;
}

/**
 * @brief Locates the first occurrence of a substring in a string.
 * 
 * This function searches the string `haystack` for the first occurrence of the substring `needle`.
 * 
 * @param haystack Pointer to the string to be searched.
 * @param needle Pointer to the substring to search for.
 * @return A pointer to the beginning of the found substring, or NULL if not found.
 */
char *strstr(const char *haystack, const char *needle)
{
	if (!*needle) {
		return (char *)haystack;
	}
	for (; *haystack; haystack++) {
		if (*haystack == *needle) {
			const char *h = haystack;
			const char *n = needle;
			while (*h && *n && *h == *n) {
				h++;
				n++;
			}
			if (!*n) {
				return (char *)haystack;
			}
		}
	}
	return NULL;
}

/**
 * @brief Tokenizes a string using a set of delimiters.
 * 
 * This function splits the string `s` into tokens separated by characters in `delim`.
 * 
 * @param s Pointer to the string to tokenize, or NULL to continue tokenizing the previous string.
 * @param delim Pointer to the string containing the delimiter characters.
 * @return A pointer to the next token, or NULL if no more tokens are found.
 */
char *strtok(char *restrict s, const char *restrict delim)
{
	static char *saveptr;
	return strtok_r(s, delim, &saveptr);
}

/**
 * @brief Tokenizes a string using a set of delimiters, with reentrancy support.
 * 
 * This function splits the string `s` into tokens separated by characters in `delim`.
 * It uses `saveptr` to maintain state between calls.
 * 
 * @param s Pointer to the string to tokenize, or NULL to continue tokenizing the previous string.
 * @param delim Pointer to the string containing the delimiter characters.
 * @param saveptr Pointer to a char* variable that stores the state between calls.
 * @return A pointer to the next token, or NULL if no more tokens are found.
 */
char *strtok_r(char *restrict s, const char *restrict delim,
	       char **restrict saveptr)
{
	char *token;
	if (s == NULL) {
		s = *saveptr;
	}
	s += strspn(s, delim);
	if (*s == '\0') {
		return NULL;
	}
	token = s;
	s = strpbrk(token, delim);
	if (s) {
		*s = '\0';
		*saveptr = s + 1;
	} else {
		*saveptr = strchr(token, '\0');
	}
	return token;
}

/**
 * @brief Transforms a string according to the current locale.
 * 
 * This function transforms the string `src` into a form suitable for comparison
 * using `strcoll`, storing the result in `dest`.
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @param n Size of the destination buffer.
 * @return The length of the transformed string (excluding the null terminator).
 */
size_t strxfrm(char *restrict dest, const char *restrict src, size_t n)
{
	size_t len = strlen(src);
	if (n > 0) {
		size_t copy_len = (len >= n) ? n - 1 : len;
		memcpy(dest, src, copy_len);
		dest[copy_len] = '\0';
	}
	return len;
}

/**
 * @brief Transforms a string according to a specified locale.
 * 
 * This function is similar to `strxfrm`, but uses the specified locale.
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @param n Size of the destination buffer.
 * @param locale The locale to use for the transformation.
 * @return The length of the transformed string (excluding the null terminator).
 */
size_t strxfrm_l(char *restrict dest, const char *restrict src, size_t n,
		 locale_t locale)
{
	(void)locale; // Locale-specific transformation not implemented.
	return strxfrm(dest, src, n);
}
