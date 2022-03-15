//
// Created by Remyf on 2/26/2022.
//

#ifndef LEAD_STD_STRING_H
#define LEAD_STD_STRING_H

#include "primitives.h"
#include "array_list.h"

typedef struct String {
    char* data;
    usize count;
} String;

void string_new(String* self, const char* str);
void string_clone(String* self, const String* str);

void string_append(String* self, const char* other);
void string_append_string(String* self, String* other);
void string_append_char(String* self, char c);

void string_insert(String* self, const char* other, usize index);
void string_insert_string(String* self, String* other, usize index);
void string_insert_char(String* self, char c, usize index);

void string_replace(String* self, const char* other, usize start, usize end);
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

void string_free(String* self);

#endif //LEAD_STD_STRING_H
