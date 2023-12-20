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

#ifndef _ARRAY_BUFFER_INT_H_
#define _ARRAY_BUFFER_INT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>

#define ARRAY_BUFFER_INT_EXPONENTIAL_GROWTH 2

typedef struct ArrayBufferInt {

    int length;
    int capacity;
    int *array;

} ArrayBufferInt;

ArrayBufferInt *initializeArrayBufferInt(unsigned int capacity);
ssize_t appendArrayInt(ArrayBufferInt *buffer, int element); // Adds an element at the end of the list
ssize_t clearArrayInt(ArrayBufferInt *buffer); // "Removes" all the elements from the list, but only sets the length to 0
ssize_t hardClearArrayInt(ArrayBufferInt *buffer); // Removes all the elements from the list, sets length to 0 and all elements to 0
ArrayBufferInt *copyArrayInt(ArrayBufferInt *buffer); // Returns a copy of the list
unsigned int countArrayInt(ArrayBufferInt *buffer, int value); // Returns the number of elements with the specified value
ssize_t extendArrayInt(ArrayBufferInt *buffer, int *elements, unsigned int number_of_elements); // Add the elements of a list (or any iterable), to the end of the current list
ssize_t indexArrayInt(ArrayBufferInt *buffer, int value); // Returns the index of the first element with the specified value
ssize_t insertArrayInt(ArrayBufferInt *buffer, int element, unsigned int pos); // Adds an element at the specified position
ssize_t popArrayInt(ArrayBufferInt *buffer, int pos); // Removes the element at the specified position
int removeArrayInt(ArrayBufferInt *buffer, int value); // Removes the first item with the specified value
ssize_t reverseArrayInt(ArrayBufferInt *buffer); // Reverses the order of the list
ssize_t sortArrayInt(ArrayBufferInt *buffer); // Sorts the list

#endif // _ARRAY_BUFFER_INT_H_