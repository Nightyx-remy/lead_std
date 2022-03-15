//
// Created by remy on 3/13/22.
//

#ifndef LEAD_STD_MEM_H
#define LEAD_STD_MEM_H

#include <stdlib.h>

/**
 * Return a memory block the correct size
 * Store the created ptr in a memory pool
 *
 * @param size the size of the memory block
 * @return the create ptr
 */
void* ld_new(size_t size);

/**
 * Check if the ptr has been allocated using ld_new() and free it if true
 * @param ptr the desired ptr
 */
void ld_free(void* ptr);

/**
 * Allocate a memory block of the correct size and check if it has successfully been allocated
 *
 * @param size the size of the memory block
 * @return the created ptr
 */
void* checked_malloc(size_t size);

/**
 * Resize a memory block to the correct size and check if it has successfully been resized
 *
 * @param ptr the resized ptr
 * @param size the size of the new ptr
 * @return the address of the new ptr
 */
void* checked_realloc(void* ptr, size_t size);

#endif //LEAD_STD_MEM_H
