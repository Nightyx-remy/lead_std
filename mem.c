#include "mem.h"
#include "io.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                 [Private] MemPool                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct MemPool {
    void** data;
    size_t capacity;
    size_t count;
} MemPool;

MemPool* mem_pool_new() {
    MemPool* self = malloc(sizeof(MemPool));
    self->capacity = 10;
    self->count = 0;
    self->data = malloc(sizeof(void*) * self->capacity);
}

void mem_pool_free(MemPool* self) {
    free(self->data);
    free(self);
}

void mem_pool_push(MemPool* self, void* data) {
    if (self->count >= self->capacity) {
        self->capacity *= 2;
        self->data = realloc(self->data, sizeof(void*) * self->capacity);
    }
    self->data[self->count++] = data;
}

void mem_pool_remove(MemPool* self, int index) {
    if (index >= 0 && index < self->count) {
        for (size_t i = index + 1; i < self->count; i++) {
            self->data[i - 1] = self->data[i];
        }
        self->count--;
    }
}

int mem_pool_index_of(MemPool* self, void* data) {
    for (size_t i = 0; i < self->count; i++) {
        if (self->data[i] == data) {
            return i;
        }
    }
    return -1;
}

MemPool* mem_pool_get() {
    static MemPool* pool = NULL;
    if (pool == NULL) {
        pool = mem_pool_new();
    }
    return pool;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                 Static functions                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void* ld_new(size_t size) {
    void* ptr = malloc(size);
    mem_pool_push(mem_pool_get(), ptr);
    return ptr;
}

void ld_free(void* ptr) {
    MemPool* pool = mem_pool_get();
    int index = mem_pool_index_of(pool, ptr);
    if (index != -1) {
        mem_pool_remove(pool, index);
        free(ptr);
    }
}

void* checked_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        throw_error(LEAD_OUT_OF_MEMORY, "Failed to create buffer of size %d bytes", size);
    }
    return ptr;
}

void* checked_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (!ptr) {
        throw_error(LEAD_OUT_OF_MEMORY, "Failed to resize buffer to size %d bytes", size);
    }
    return new_ptr;
}