#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                     LeadError                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char* lead_error_to_string(LeadError self) {
    switch (self) {
        case LEAD_OUT_OF_MEMORY:
            return "OutOfMemory";
        case LEAD_OUT_OF_BOUNDS:
            return "OutOfBounds";
        case LEAD_UNWRAP_OF_NONE:
            return "UnwrapOfNone";
        case LEAD_OPERATION_FAILED:
            return "OperationFailed";
        default:
            return "Unknown";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                 Static Functions                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void panic(char* fmt, ...) {
    va_list args;

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    exit(-1);
}

void throw_error(LeadError error, char* fmt, ...) {
    va_list args;

    fprintf(stderr, "[%s]: ", lead_error_to_string(error));

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    fprintf(stderr, "\n");

    exit(-1);
}