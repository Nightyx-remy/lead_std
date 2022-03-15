#include "array_list.h"

#include "mem.h"

ArrayList* array_list_new() {
    ArrayList* self = ld_new(sizeof(ArrayList));
    self->count = 0;
    self->capacity = ARRAY_LIST_CAPACITY;
    // The content of the arraylist is not allocated using lead since it's meant to be resized
    self->data = checked_malloc(sizeof(void*) * self->capacity);
    return self;
}

void array_list_push(ArrayList* self, void* element) {
    // Resize ArrayList
    if (self->count >= self->capacity) {
        self->capacity *= 2;
        self->data = checked_realloc(self->data, sizeof(void*) * self->capacity);
    }

    // Push element
    self->data[self->count++] = element;
}

void* array_list_pop(ArrayList* self) {
    if (self->count > 0) {
        return self->data[--self->count];
    } else {
        throw_error(LEAD_OPERATION_FAILED, "Failed to pop element from ArrayList, the ArrayList is empty!");
    }
}

void array_list_append(ArrayList* self, ArrayList* other) {
    // Resize ArrayList
    while (self->count + other->count >= self->capacity) {
        self->capacity *= 2;
        self->data = checked_realloc(self->data, sizeof (void*) * self->capacity);
    }

    // Append ArrayList
    for (usize i = 0; i < other->count; i++) {
        self->data[self->count++] = other->data[i];
    }

    // Free other ArrayList
    array_list_free(other);
}

void array_list_insert(ArrayList* self, usize index, void* element) {
    // Check if the index is OutOfBounds
    if (index > self->count) {
        throw_error(LEAD_OUT_OF_BOUNDS, "Failed to insert element at index %d, should be in range [0; %d]", index, self->count);
    }

    // Resize the ArrayList
    if (self->count >= self->capacity) {
        self->capacity *= 2;
        self->data = checked_realloc(self->data, sizeof(void*) * self->capacity);
    }

    // Shift the elements
    for (usize i = self->count; i >= index; i--) {
        self->data[i + 1] = self->data[i];
    }

    // Insert the element
    self->data[index] = element;
    self->count++;
}

void* array_list_replace(ArrayList* self, usize index, void* element) {
    // Check if the index is OutOfBounds
    if (index > self->count) {
        throw_error(LEAD_OUT_OF_BOUNDS, "Failed to replace element at index %d, should be in range [0; %d]", index, self->count);
    }

    // Store the replaced element
    void* temp = self->data[index];

    // Replace the element
    self->data[index] = element;

    return temp;
}

void* array_list_get(ArrayList* self, usize index) {
    // Check if the index is OutOfBounds
    if (index > self->count) {
        throw_error(LEAD_OUT_OF_BOUNDS, "Failed to get element at index %d, should be in range [0; %d]", index, self->count);
    }

    return self->data[index];
}

void array_list_foreach(ArrayList* self, void(*func)(usize, void*)) {
    for (usize i = 0; i < self->count; i++) {
        func(i, self->data[i]);
    }
}

void array_list_free(ArrayList* self) {
    free(self->data);
    ld_free(self);
}
