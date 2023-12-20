/*
MIT License

Copyright (c) 2023 Hamon-Rá Taveira Guimarães

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _ARRAYBUFFER_H_
#define _ARRAYBUFFER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// https://en.wikipedia.org/wiki/C_data_types
#define ARRAY_SHORT_TYPE 0
#define ARRAY_SHORT_INT_TYPE 1
#define ARRAY_SIGNED_SHORT_TYPE 2
#define ARRAY_SIGNED_SHORT_INT_TYPE 3
#define ARRAY_UNSIGNED_SHORT_TYPE 4
#define ARRAY_UNSIGNED_SHORT_INT_TYPE 5
#define ARRAY_INT_TYPE 6
#define ARRAY_SIGNED_TYPE 7
#define ARRAY_SIGNED_INT_TYPE 8
#define ARRAY_UNSIGNED_TYPE 9
#define ARRAY_UNSIGNED_INT_TYPE 10
#define ARRAY_LONG_TYPE 11
#define ARRAY_LONG_INT_TYPE 12
#define ARRAY_SIGNED_LONG_TYPE 13
#define ARRAY_SIGNED_LONG_INT_TYPE 14
#define ARRAY_UNSIGNED_LONG_TYPE 15
#define ARRAY_UNSIGNED_LONG_INT_TYPE 16
#define ARRAY_LONG_LONG_TYPE 17
#define ARRAY_LONG_LONG_INT_TYPE 18
#define ARRAY_SIGNED_LONG_LONG_TYPE 19
#define ARRAY_SIGNED_LONG_LONG_INT_TYPE 20
#define ARRAY_UNSIGNED_LONG_LONG_TYPE 21
#define ARRAY_UNSIGNED_LONG_LONG_INT_TYPE 22
#define ARRAY_FLOAT_TYPE 23
#define ARRAY_DOUBLE_TYPE 24
#define ARRAY_LONG_DOUBLE_TYPE 25

typedef union ArrayBufferType {
    short short_type;
    short int short_int_type;
    signed short signed_short_type;
    signed short int signed_short_int_type;
    unsigned short unsigned_short_type;
    unsigned short int unsigned_short_int_type;
    int int_type;
    signed signed_type;
    signed int signed_int_type;
    unsigned unsigned_type;
    unsigned int unsigned_int_type;
    long long_type;
    long int long_int_type;
    signed long signed_long_type;
    signed long int signed_long_int_type;
    unsigned long unsigned_long_type;
    unsigned long int unsigned_long_int_type;
    long long long_long_type;
    long long int long_long_int_type;
    signed long long signed_long_long_type;
    signed long long int signed_long_long_int_type;
    unsigned long long unsigned_long_long_type;
    unsigned long long int unsigned_long_long_int_type;
    float float_type;
    double double_type;
    long double long_double_type;
} ArrayBufferType;

typedef struct ArrayBuffer {

    unsigned int type;
    unsigned int length;
    unsigned int capacity;
    ArrayBufferType *data;

} ArrayBuffer;

ArrayBuffer *initializeArrayBuffer(unsigned int capacity, int type);
unsigned int append(ArrayBufferType data); // Adds an element at the end of the list
unsigned int clear(); // Removes all the elements from the list
ArrayBuffer *copy(); // Returns a copy of the list
unsigned int count(); // Returns the number of elements with the specified value
ArrayBuffer *extend(ArrayBuffer *buffer); // Add the elements of a list (or any iterable), to the end of the current list
unsigned int index(ArrayBuffer data); // Returns the index of the first element with the specified value
unsigned int insert(unsigned int pos, ArrayBufferType *data); // Adds an element at the specified position
ArrayBufferType pop(int pos); // Removes the element at the specified position
ArrayBufferType remove(ArrayBuffer data); // Removes the first item with the specified value
unsigned int reverse(ArrayBuffer *buffer); // Reverses the order of the list
unsigned int sort(ArrayBuffer *buffer); // Sorts the list

#endif // _ARRAYBUFFER_H_