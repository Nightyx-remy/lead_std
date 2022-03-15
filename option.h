#ifndef LEAD_STD_OPTION_H
#define LEAD_STD_OPTION_H

#include <stdlib.h>
#include "primitives.h"

typedef struct Option {
    void* data;
} Option;

/**
 * Create a new Option containing data
 *
 * @param data the data that the option contains (or null for None option)
 * @return a copy of the created Option
 */
Option option_new(void* data);

/**
 * Create a None Option (containing nothing)
 *
 * @return the copy of the created Option
 */
Option option_none();

/**
 * Check if an option is None
 *
 * @param self the option to check
 * @return true if the option is None, false otherwise
 */
bool option_is_none(Option* self);

/**
 * Check if an option contains something
 *
 * @param self the option to check
 * @return true if the option contains something, false otherwise
 */
bool option_is_some(Option* self);

/**
 * Returns the data that the Option contains.
 * If the option is none, throw an UnwrapOfNone error
 *
 * @param self the Option to unwrap
 * @return the data contained by the Option
 */
void* option_unwrap(Option* self);

/**
 * Returns the data that the Option contains.
 * If the option is none, return the other (default value)
 *
 * @param self the Option to unwrap
 * @param other the value to return if the Option is None
 * @return the data contained by Option or the given value
 */
void* option_unwrap_or(Option* self, void* other);

/**
 * Replace the data contained by the Option.
 *
 * @param self the Option to modify
 * @param value the new value
 * @return the data previously contained by the Option (or null if None)
 */
void* option_replace(Option* self, void* value);

/**
 * Create an option from a function and a boolean
 *
 * @param self
 * @param func the function to execute if self is true
 * @return None if self is false, otherwise return the value returned by the given function
 */
Option bool_then(bool self, Option(*func)());

#endif //LEAD_STD_OPTION_H
