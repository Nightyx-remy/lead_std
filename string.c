//
// Created by Remyf on 2/26/2022.
//

#include "string.h"
#include <string.h>

void string_new(String* self, const char* str) {
    size_t str_len = strlen(str);
    self->data = malloc(sizeof(char) * (str_len + 1));
    self->count = str_len;
    memcpy(self->data, str, sizeof(char) * str_len);
    self->data[str_len] = '\0';
}

void string_clone(String* self, const String* str) {
    self->data = malloc(sizeof(char) * (str->count + 1));
    self->count = str->count;
    memcpy(self->data, str->data, sizeof(char) * str->count);
    self->data[self->count] = '\0';
}

void string_append(String* self, const char* other) {
    size_t str_len = strlen(other);
    self->data = realloc(self->data, sizeof(char) * (self->count + str_len + 1));
    memcpy(self->data + self->count, other, sizeof(char) * str_len);
    self->count += str_len;
    self->data[self->count] = '\0';
}

void string_append_string(String* self, String* other) {
    self->data = realloc(self->data, sizeof(char) * (self->count + other->count + 1));
    memcpy(self->data + self->count, other->data, sizeof(char) * other->count);
    self->count += other->count;
    self->data[self->count] = '\0';
}

void string_append_char(String* self, char c) {
    self->data = realloc(self->data, sizeof(char) * (self->count + 2));
    self->data[self->count++] = c;
    self->data[self->count] = '\0';
}

void string_insert(String* self, const char* other, usize index) {
    size_t str_len = strlen(other);
    self->data = realloc(self->data, sizeof(char) * (self->count + str_len + 1));
    for (usize i = self->count; i >= index; i--) {
        self->data[i + str_len] = self->data[i];
    }
    memcpy(self->data + index, other, sizeof(char) * str_len);
    self->count += str_len;
    self->data[self->count] = '\0';
}

void string_insert_string(String* self, String* other, usize index) {
    self->data = realloc(self->data, sizeof(char) * (self->count + other->count + 1));
    for (usize i = self->count; i >= index; i--) {
        self->data[i + other->count] = self->data[i];
    }
    memcpy(self->data + index, other->data, sizeof(char) * other->count);
    self->count += other->count;
    self->data[self->count] = '\0';
}

void string_insert_char(String* self, char c, usize index) {
    self->data = realloc(self->data, sizeof(char) * (self->count + 1));
    for (usize i = self->count; i >= index; i--) {
        self->data[i + 1] = self->data[i];
    }
    self->data[index] = c;
    self->count += 1;
    self->data[self->count] = '\0';
}

void string_replace(String* self, const char* other, usize start, usize end) {
    if (start < end && end <= self->count) {
        usize replace_len = end - start;
        size_t str_len = strlen(other);
        if (replace_len > str_len) {
            // Shrinking
            for (usize i = self->count; i >= end; i--) {
                self->data[i + str_len - replace_len] = self->data[i];
            }
            self->data = realloc(self->data, sizeof(char) * (self->count - replace_len + str_len + 1));
            memcpy(self->data + start, other, sizeof(char) * str_len);
            self->count += str_len - replace_len;
            self->data[self->count] = '\0';
        } else if (replace_len < str_len) {
            // Stretching
            self->data = realloc(self->data, sizeof(char) * (self->count - replace_len + str_len + 1));
            for (usize i = self->count; i >= end; i--) {
                self->data[i + str_len - replace_len] = self->data[i];
            }
            memcpy(self->data + start, other, sizeof(char) * str_len);
            self->count += str_len - replace_len;
            self->data[self->count] = '\0';
        } else {
            // Same size
            memcpy(self->data + start, other, sizeof(char) * str_len);
        }
    }
}

void string_replace_string(String* self, const char* other, usize start, usize end);

void string_replace_char(String* self, const char* other, usize start, usize end);

void string_remove(String* self, usize start, usize end);

isize string_find(String* self, const char* other);
isize string_find_string(String* self, String* other);
isize string_find_char(String* self, char c);

isize string_rfind(String* self, const char* other);
isize string_rfind_string(String* self, String* other);
isize string_rfind_char(String* self, char c);

String string_sub_string(String* self, usize start, usize end);

ArrayList string_split(String* self, const char* separator);
ArrayList string_split_string(String* self, String separator);
ArrayList string_split_char(String* self, char c);

ArrayList string_split_x(String* self, const char* separator, usize amount);
ArrayList string_split_x_string(String* self, String separator, usize amount);
ArrayList string_split_x_char(String* self, char c, usize amount);

void string_free(String* self) {
    free(self->data);
    self->count = 0;
}
