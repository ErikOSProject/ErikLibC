/**
 * @file malloc.c
 * @brief Memory allocation functions.
 * 	
 * This file contains implementations of memory allocation functions such as
 * malloc and free. These functions are used to manage dynamic memory
 * allocation in the program.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _heap_block heap_block;
struct _heap_block {
	bool used;
	size_t size;
	heap_block *previous;
	heap_block *next;
};

static uintptr_t heap_start;
static uintptr_t heap_end;
static heap_block *first_block;
static heap_block *last_block;

static char heap_buffer[0x100];

/**
 * @brief Splits a heap block into two blocks.
 *
 * This function takes a pointer to the first block and a size, and splits the 
 * first block into two blocks. The first block will have the specified size, 
 * and the second block will contain the remaining space.
 *
 * @param first Pointer to the first heap block to be split.
 * @param size The size of the first block after the split.
 */
static void heap_split_block(heap_block *first, size_t size)
{
	heap_block *second =
		(heap_block *)((uintptr_t)first + sizeof(heap_block) + size);
	size_t second_size = first->size - size - sizeof(heap_block);

	second->used = false;
	second->previous = first;
	second->next = first->next;
	second->size = second_size;
	first->next = second;
	first->size = size;
	if (second->next)
		second->next->previous = second;

	if (last_block == first)
		last_block = second;
}

/**
 * @brief Merges two adjacent heap blocks into a single block.
 *
 * This function takes two adjacent heap blocks and merges them into a single
 * block. The first block should be the one that comes before the second block
 * in memory. After merging, the first block will encompass the memory of both
 * blocks, and the second block will no longer be valid.
 *
 * @param first Pointer to the first heap block.
 * @param second Pointer to the second heap block.
 */
static void heap_merge_blocks(heap_block *first, heap_block *second)
{
	if (second->next)
		second->next->previous = first;
	first->next = second->next;
	first->size += second->size + sizeof(heap_block);

	if (last_block == second)
		last_block = first;
}

/**
 * @brief Expands the heap to accommodate more memory.
 *
 * This function attempts to increase the size of the heap to provide
 * additional memory for allocation. It does this by mapping a new page
 * of memory and adding it to the heap as a new block.
 *
 * @return true if the heap was successfully expanded, false otherwise.
 */
static bool expand_heap(void)
{
	// TODO: Implement heap expansion logic
	return false;
}

/**
 * @brief Initializes the heap.
 * 
 * This function initializes the heap by setting up the first block of memory
 * and marking it as free. It sets the start and end pointers of the heap
 * and initializes the first block.
 */
void heap_init(void)
{
	heap_start = (uintptr_t)heap_buffer;
	heap_end = heap_start + sizeof(heap_buffer);

	last_block = first_block = (heap_block *)heap_start;
	first_block->size = sizeof(heap_buffer) - sizeof(heap_block);
	first_block->previous = NULL;
	first_block->next = NULL;
	first_block->used = false;
}

/**
 * @brief Allocates a block of memory on the heap. (helper function)
 *
 * This function allocates a block of memory of the specified size on the heap.
 * Returns NULL if the allocation fails. Use malloc() instead of this function to
 * allocate memory allowing the heap to expand if necessary.
 *
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory block, or NULL if the allocation fails.
 */
static heap_block *do_malloc(size_t size)
{
	heap_block *i = first_block;
	while (i) {
		if (!i->used && i->size >= size) {
			if (i->size > size + 2 * sizeof(heap_block))
				heap_split_block(i, size);
			i->used = true;
			return i;
		}
		i = i->next;
	}
	return NULL;
}

/**
 * @brief Allocates a block of memory on the heap.
 *
 * This function allocates a block of memory of the specified size on the heap.
 * If the allocation fails, it attempts to expand the heap to accommodate the
 * requested memory size.
 *
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory block, or NULL if the allocation fails.
 */
void *malloc(size_t size)
{
	heap_block *i = NULL;
	while (true) {
		if ((i = do_malloc(size)))
			return (uint8_t *)i + sizeof(heap_block);
		if (!expand_heap())
			return NULL;
	}
}

/**
 * @brief Frees the memory space pointed to by ptr, which must have been returned by a previous call to malloc().
 *
 * @param ptr Pointer to the memory to be freed.
 */
void free(void *ptr)
{
	heap_block *i = (heap_block *)((uintptr_t)ptr - sizeof(heap_block));
	if ((uintptr_t)i < heap_start || (uintptr_t)i >= heap_end)
		return;
	i->used = false;

	if (i->next && !i->next->used)
		heap_merge_blocks(i, i->next);
	if (i->previous && !i->previous->used)
		heap_merge_blocks(i->previous, i);
}
