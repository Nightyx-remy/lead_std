#ifndef LEAD_STD_ARRAY_LIST_H
#define LEAD_STD_ARRAY_LIST_H

#include <stdlib.h>
#include "primitives.h"
#include "io.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                     ArrayList                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ARRAY_LIST_CAPACITY 0b100

typedef struct ArrayList {
    void** data;
    usize count;
    usize capacity;
} ArrayList;

/**
 * Create a new ArrayList with a capacity of ARRAY_LIST_CAPACITY
 *
 * @return the created ArrayList
 */
ArrayList* array_list_new();

/**
 * Push an element in the ArrayList
 *
 * @param self the ArrayList being modified
 * @param element the element being pushed
 */
void array_list_push(ArrayList* self, void* element);

/**
 * Pop the element on top of the ArrayList
 *
 * @param self the ArrayList being modified
 * @return the popped element
 */
void* array_list_pop(ArrayList* self);

/**
 * Append the current ArrayList by an other ArrayList
 * Free the other ArrayList.
 *
 * @param self the ArrayList being modified
 * @param other the ArrayList being appended
 */
void array_list_append(ArrayList* self, ArrayList* other);

/**
 * Insert an element at a certain index in the ArrayList
 *
 * @param self the ArrayList being modified
 * @param index the index at which the element will be inserted
 * @param element the element being inserted
 */
void array_list_insert(ArrayList* self, usize index, void* element);

/**
 * Replace an element at a certain index by a new element.
 *
 * @param self the ArrayList being modified
 * @param index the index of the element being replaced
 * @param element the replacing element
 * @return the replaced element
 */
void* array_list_replace(ArrayList* self, usize index, void* element);

/**
 * Get the element at a certain index
 *
 * @param self the ArrayList being looked through
 * @param index the index of the element
 * @return the element found or NULL
 */
void* array_list_get(ArrayList* self, usize index);

/**
 * Look for the 1st matching element from the left of the ArrayList
 *
 * @param self the ArrayList being looked through
 * @param element the searched element
 * @param eq_func the equal function of the element (or NULL for default)
 * @return the index of the 1st element found or -1
 */
isize array_list_find(ArrayList* self, void* element, bool(*eq_func)(void*, void*));

/**
 * Look for the 1st matching element from the right of the ArrayList
 *
 * @param self the ArrayList being looked through
 * @param element the searched element
 * @param eq_func the equal function of the element (or NULL for default)
 * @return the index of the 1st element found or -1
 */
isize array_list_rfind(ArrayList* self, void* element, bool(*eq_func)(void*, void*));

/**
 * Execute the given function for each element inside the ArrayList
 *
 * @param self the ArrayList being iterated
 * @param func the function executed for each element
 */
void array_list_foreach(ArrayList* self, void(*func)(usize, void*));

/**
 * Free the ArrayList
 *
 * @param self the ArrayList being freed
 */
void array_list_free(ArrayList* self);

#endif //LEAD_STD_ARRAY_LIST_H
