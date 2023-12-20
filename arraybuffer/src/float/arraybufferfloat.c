#include "./arraybufferfloat.h"

ArrayBufferfloat *initializeArrayBufferfloat(float capacity) {

    if(capacity == 0) return NULL;

    ArrayBufferfloat *tmp = (ArrayBufferfloat*)malloc(sizeof(ArrayBufferfloat));
    if(tmp == NULL) return NULL;

    tmp->array = (float*)malloc(sizeof(float) * capacity);
    if(tmp->array == NULL) {
        free(tmp);
        return NULL;
    };
    memset(tmp->array, 0, sizeof(float) * capacity);

    tmp->capacity = capacity;
    tmp->length = 0;

    return tmp;
};

ssize_t appendArrayfloat(ArrayBufferfloat *buffer, float element) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    if(buffer->length >= buffer->capacity) {

        int new_capacity = buffer->length * ARRAY_BUFFER_FLOAT_EXPONENTIAL_GROWTH;

        float *tmp = (float*)malloc(new_capacity * sizeof(buffer->array[0]));
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
ssize_t clearArrayfloat(ArrayBufferfloat *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    buffer->length = 0;

    return 1;
};

// Removes all the elements from the list, sets length to 0 and all elements to 0
ssize_t hardClearArrayfloat(ArrayBufferfloat *buffer) {
    
    if(buffer == NULL || buffer->array == NULL) return -1;

    memset(buffer->array, 0, sizeof(buffer->array[0]) * buffer->length);
    buffer->length = 0;

    return 1;
};

ArrayBufferfloat *copyArrayfloat(ArrayBufferfloat *buffer) {

    if(buffer == NULL || buffer->array == NULL) return NULL;

    ArrayBufferfloat *tmp = (ArrayBufferfloat*)malloc(sizeof(ArrayBufferfloat));
    if(tmp == NULL) return NULL;

    tmp->array = (float*)malloc(buffer->length * sizeof(buffer->array[0]));
    if(tmp->array == NULL) {
        free(tmp);
        return NULL;
    };

    memcpy(tmp->array, buffer->array, buffer->length * sizeof(buffer->array[0]));
    tmp->capacity = buffer->capacity;
    tmp->length = buffer->length;

    return tmp;
};

float countArrayfloat(ArrayBufferfloat *buffer, float value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    int count = 0;

    for(unsigned int i = 0; i < buffer->length; i++) {
        if(buffer->array[i] == value) count++;
    };

    return count;
};


// Add the elements of an array, to the end of the current list
ssize_t extendArrayfloat(ArrayBufferfloat *buffer, float *elements, unsigned int number_of_elements) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    unsigned int new_capacity = number_of_elements + buffer->length;

    if(new_capacity >= buffer->capacity) {

        float *tmp = (float*)malloc(sizeof(buffer->array[0]) * new_capacity);
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

ssize_t indexArrayfloat(ArrayBufferfloat *buffer, float value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    for(int i = 0; i < buffer->length; i++) {
        if(buffer->array[i] == value) return i;  
    };

    return -1;

};

// Adds an element at the specified position
ssize_t insertArrayfloat(ArrayBufferfloat *buffer, float element, unsigned int pos) {

    if(buffer == NULL || buffer->array == NULL || pos < 0) return -1;

    unsigned int new_capacity = buffer->length + 1;

    unsigned long size_of_first_element = sizeof(buffer->array[0]);

    float *tmp = (float*)malloc(sizeof(buffer->array[0]) * new_capacity);
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
ssize_t popArrayfloat(ArrayBufferfloat *buffer, unsigned int pos) {

    if(buffer == NULL || buffer->array == NULL || pos < 0) return -1;

    memmove(buffer->array + pos, buffer->array + pos + 1, (buffer->length - pos - 1) * sizeof(buffer->array[0]));

    buffer->length--;

    return 1;

};

float removeArrayfloat(ArrayBufferfloat *buffer, float value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    unsigned int pos = 0;
    float to_be_removed = 0;

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
ssize_t reverseArrayfloat(ArrayBufferfloat *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    float *tmp = (float*)malloc(sizeof(buffer->array[0]) * buffer->capacity);
    if(tmp == NULL) return -1;

    for(int i = 0; i < buffer->length; i++) {
        tmp[i] = buffer->array[buffer->length - i - 1];
    };

    free(buffer->array);
    buffer->array = tmp;

    return 1;

};

int qsortCompfloat(const void *a, const void *b) {
    return *(float*)a - *(float*)b;
};

ssize_t sortArrayfloat(ArrayBufferfloat *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    qsort(buffer->array, buffer->length, sizeof(buffer->array[0]), qsortCompfloat);

    return 1;
};