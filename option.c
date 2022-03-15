#include "option.h"
#include "io.h"

Option option_new(void* data) {
    Option self;
    self.data = data;
    return self; // Returns a copy
}

Option option_none() {
    return option_new(NULL);
}

bool option_is_none(Option* self) {
    return self->data == NULL;
}

bool option_is_some(Option* self) {
    return self->data != NULL;
}

void* option_unwrap(Option* self) {
    if (self->data == NULL) {
        throw_error(LEAD_UNWRAP_OF_NONE, "Attempt to unwrap empty option");
    }
    return self->data;
}

void* option_unwrap_or(Option* self, void* other) {
    if (self->data == NULL) {
        return other;
    }
    return self->data;
}

void* option_replace(Option* self, void* value) {
    void* temp = self->data;
    self->data = value;
    return temp;
}

Option bool_then(bool self, Option(*func)()) {
    if (self) {
        return func();
    } else {
        return option_none();
    }
}