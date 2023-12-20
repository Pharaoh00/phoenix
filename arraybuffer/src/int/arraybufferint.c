#include "./arraybufferint.h"

ArrayBufferInt *initializeArrayBufferInt(unsigned int capacity) {

    if(capacity == 0) return NULL;

    ArrayBufferInt *tmp = (ArrayBufferInt*)malloc(sizeof(ArrayBufferInt));
    if(tmp == NULL) return NULL;

    tmp->array = (int*)malloc(sizeof(int) * capacity);
    if(tmp->array == NULL) {
        free(tmp);
        return NULL;
    };
    memset(tmp->array, 0, sizeof(int) * capacity);

    tmp->capacity = capacity;
    tmp->length = 0;

    return tmp;
};

ssize_t appendArrayInt(ArrayBufferInt *buffer, int element) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    if(buffer->length >= buffer->capacity) {

        int new_capacity = buffer->length * ARRAY_BUFFER_INT_EXPONENTIAL_GROWTH;

        int *tmp = (int*)malloc(new_capacity * sizeof(buffer->array[0]));
        if(tmp == NULL) return -1;

        memcpy(tmp, buffer->array, buffer->length * sizeof(buffer->array[0]));
        tmp[buffer->length] = element;

        free(buffer->array);
        buffer->array = tmp;

        buffer->capacity = new_capacity;
        buffer->length++;

        return 1;
    };

    buffer->array[buffer->length++] = element;

    return 1;
};

// "Removes" all the elements from the list, but only sets the length to 0
ssize_t clearArrayInt(ArrayBufferInt *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    buffer->length = 0;

    return 1;
};

// Removes all the elements from the list, sets length to 0 and all elements to 0
ssize_t hardClearArrayInt(ArrayBufferInt *buffer) {
    
    if(buffer == NULL || buffer->array == NULL) return -1;

    memset(buffer->array, 0, sizeof(buffer->array[0]) * buffer->length);
    buffer->length = 0;

    return 1;
};

ArrayBufferInt *copyArrayInt(ArrayBufferInt *buffer) {

    if(buffer == NULL || buffer->array == NULL) return NULL;

    ArrayBufferInt *tmp = (ArrayBufferInt*)malloc(sizeof(ArrayBufferInt));
    if(tmp == NULL) return NULL;

    tmp->array = (int*)malloc(buffer->length * sizeof(buffer->array[0]));
    if(tmp->array == NULL) {
        free(tmp);
        return NULL;
    };

    memcpy(tmp->array, buffer->array, buffer->length * sizeof(buffer->array[0]));
    tmp->capacity = buffer->capacity;
    tmp->length = buffer->length;

    return tmp;
};

unsigned int countArrayInt(ArrayBufferInt *buffer, int value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    unsigned int count = 0;

    for(unsigned int i = 0; i < buffer->length; i++) {
        if(buffer->array[i] == value) count++;
    };

    return count;
};


// Add the elements of an array, to the end of the current list
ssize_t extendArrayInt(ArrayBufferInt *buffer, int *elements, unsigned int number_of_elements) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    unsigned int new_capacity = number_of_elements + buffer->length;

    if(new_capacity >= buffer->capacity) {

        int *tmp = (int*)malloc(sizeof(buffer->array[0]) * new_capacity);
        if(tmp == NULL) return -1;

        memcpy(tmp, buffer->array, buffer->length);
        memcpy(tmp + buffer->length, elements, number_of_elements);

        free(buffer->array);
        buffer->array = tmp;
        buffer->capacity = new_capacity;
        buffer->length = new_capacity;

        return 1;
    };

    memcpy(buffer->array + buffer->length, elements, number_of_elements);
    buffer->length = new_capacity;

    return 1;

};

ssize_t indexArrayInt(ArrayBufferInt *buffer, int value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    for(int i = 0; i < buffer->length; i++) {
        if(buffer->array[i] == value) return i;  
    };

    return -1;

};

// Adds an element at the specified position
ssize_t insertArrayInt(ArrayBufferInt *buffer, int element, unsigned int pos) {

    if(buffer == NULL || buffer->array == NULL || pos < 0) return -1;

    unsigned int new_capacity = buffer->length + 1;

    unsigned long size_of_first_element = sizeof(buffer->array[0]);

    int *tmp = (int*)malloc(sizeof(buffer->array[0]) * new_capacity);
    if(tmp == NULL) return -1;

    memcpy(tmp, buffer->array, pos * size_of_first_element);
    memcpy(tmp + pos + 1, buffer->array + pos, (buffer->length - pos) * size_of_first_element);
    tmp[pos] = element;

    free(buffer->array);
    buffer->array = tmp;
    buffer->capacity = new_capacity;
    buffer->length = new_capacity;

    return 1;

};

// Removes the element at the specified position
ssize_t popArrayInt(ArrayBufferInt *buffer, int pos) {

    if(buffer == NULL || buffer->array == NULL || pos < 0) return -1;

    memmove(buffer->array + pos, buffer->array + pos + 1, (buffer->length - pos - 1) * sizeof(buffer->array[0]));

    buffer->length--;

    return 1;

};

int removeArrayInt(ArrayBufferInt *buffer, int value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    unsigned int pos = 0;
    int to_be_removed = 0;

    for(int i = 0; i < buffer->length; i++) {
        if(buffer->array[i] == value) {
            pos = i;
            to_be_removed = buffer->array[i];
            break;
        };
    };

    memmove(buffer->array + pos, buffer->array + pos + 1, (buffer->length - pos - 1) * sizeof(buffer->array[0]));

    buffer->length--;

    return to_be_removed;

};

// Reverses the order of the array
ssize_t reverseArrayInt(ArrayBufferInt *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    int *tmp = (int*)malloc(sizeof(buffer->array[0]) * buffer->capacity);
    if(tmp == NULL) return -1;

    for(int i = 0; i < buffer->length; i++) {
        tmp[i] = buffer->array[buffer->length - i - 1];
    };

    free(buffer->array);
    buffer->array = tmp;

    return 1;

};

int qsortCompInt(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
};

ssize_t sortArrayInt(ArrayBufferInt *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    qsort(buffer->array, buffer->length, sizeof(buffer->array[0]), qsortCompInt);

    return 1;
};