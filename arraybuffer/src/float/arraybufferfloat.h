#ifndef _ARRAY_BUFFER_FLOAT_H_
#define _ARRAY_BUFFER_FLOAT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>

#define ARRAY_BUFFER_FLOAT_EXPONENTIAL_GROWTH 2

typedef struct ArrayBufferfloat {

    int length;
    int capacity;
    float *array;

} ArrayBufferfloat;

ArrayBufferfloat *initializeArrayBufferfloat(float capacity);
ssize_t appendArrayfloat(ArrayBufferfloat *buffer, float element); // Adds an element at the end of the list
ssize_t clearArrayfloat(ArrayBufferfloat *buffer); // "Removes" all the elements from the list, but only sets the length to 0
ssize_t hardClearArrayfloat(ArrayBufferfloat *buffer); // Removes all the elements from the list, sets length to 0 and all elements to 0
ArrayBufferfloat *copyArrayfloat(ArrayBufferfloat *buffer); // Returns a copy of the list
float countArrayfloat(ArrayBufferfloat *buffer, float value); // Returns the number of elements with the specified value
ssize_t extendArrayfloat(ArrayBufferfloat *buffer, float *elements, unsigned int number_of_elements); // Add the elements of a list (or any iterable), to the end of the current list
ssize_t indexArrayfloat(ArrayBufferfloat *buffer, float value); // Returns the index of the first element with the specified value
ssize_t insertArrayfloat(ArrayBufferfloat *buffer, float element, unsigned int pos); // Adds an element at the specified position
ssize_t popArrayfloat(ArrayBufferfloat *buffer, unsigned int pos); // Removes the element at the specified position
float removeArrayfloat(ArrayBufferfloat *buffer, float value); // Removes the first item with the specified value
ssize_t reverseArrayfloat(ArrayBufferfloat *buffer); // Reverses the order of the list
ssize_t sortArrayfloat(ArrayBufferfloat *buffer); // Sorts the list

#endif // _ARRAY_BUFFER_FLOAT_H_