#ifndef LEAD_STD_IO_H
#define LEAD_STD_IO_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                     LeadError                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum LeadError {
    LEAD_OUT_OF_MEMORY,
    LEAD_OUT_OF_BOUNDS,
    LEAD_UNWRAP_OF_NONE,
    LEAD_OPERATION_FAILED,
} LeadError;

const char* lead_error_to_string(LeadError self);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                 Static Functions                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Implementation of a panic function
 *
 * @param fmt the format string
 * @param ... the list of arguments
 */
void panic(char* fmt, ...);

/**
 * Implementation of a panic function
 *
 * @param error the thrown error
 * @param fmt the format string
 * @param ... the list of arguments
 */
void throw_error(LeadError error, char* fmt, ...);

#endif //LEAD_STD_IO_H
