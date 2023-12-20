#include "./arraybufferdouble.h"

ArrayBufferdouble *initializeArrayBufferdouble(double capacity) {

    if(capacity == 0) return NULL;

    ArrayBufferdouble *tmp = (ArrayBufferdouble*)malloc(sizeof(ArrayBufferdouble));
    if(tmp == NULL) return NULL;

    tmp->array = (double*)malloc(sizeof(double) * capacity);
    if(tmp->array == NULL) {
        free(tmp);
        return NULL;
    };
    memset(tmp->array, 0, sizeof(double) * capacity);

    tmp->capacity = capacity;
    tmp->length = 0;

    return tmp;
};

ssize_t appendArraydouble(ArrayBufferdouble *buffer, double element) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    if(buffer->length >= buffer->capacity) {

        int new_capacity = buffer->length * ARRAY_BUFFER_DOUBLE_EXPONENTIAL_GROWTH;

        double *tmp = (double*)malloc(new_capacity * sizeof(buffer->array[0]));
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
ssize_t clearArraydouble(ArrayBufferdouble *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    buffer->length = 0;

    return 1;
};

// Removes all the elements from the list, sets length to 0 and all elements to 0
ssize_t hardClearArraydouble(ArrayBufferdouble *buffer) {
    
    if(buffer == NULL || buffer->array == NULL) return -1;

    memset(buffer->array, 0, sizeof(buffer->array[0]) * buffer->length);
    buffer->length = 0;

    return 1;
};

ArrayBufferdouble *copyArraydouble(ArrayBufferdouble *buffer) {

    if(buffer == NULL || buffer->array == NULL) return NULL;

    ArrayBufferdouble *tmp = (ArrayBufferdouble*)malloc(sizeof(ArrayBufferdouble));
    if(tmp == NULL) return NULL;

    tmp->array = (double*)malloc(buffer->length * sizeof(buffer->array[0]));
    if(tmp->array == NULL) {
        free(tmp);
        return NULL;
    };

    memcpy(tmp->array, buffer->array, buffer->length * sizeof(buffer->array[0]));
    tmp->capacity = buffer->capacity;
    tmp->length = buffer->length;

    return tmp;
};

double countArraydouble(ArrayBufferdouble *buffer, double value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    int count = 0;

    for(unsigned int i = 0; i < buffer->length; i++) {
        if(buffer->array[i] == value) count++;
    };

    return count;
};


// Add the elements of an array, to the end of the current list
ssize_t extendArraydouble(ArrayBufferdouble *buffer, double *elements, unsigned int number_of_elements) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    unsigned int new_capacity = number_of_elements + buffer->length;

    if(new_capacity >= buffer->capacity) {

        double *tmp = (double*)malloc(sizeof(buffer->array[0]) * new_capacity);
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

ssize_t indexArraydouble(ArrayBufferdouble *buffer, double value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    for(int i = 0; i < buffer->length; i++) {
        if(buffer->array[i] == value) return i;  
    };

    return -1;

};

// Adds an element at the specified position
ssize_t insertArraydouble(ArrayBufferdouble *buffer, double element, unsigned int pos) {

    if(buffer == NULL || buffer->array == NULL || pos < 0) return -1;

    unsigned int new_capacity = buffer->length + 1;

    unsigned long size_of_first_element = sizeof(buffer->array[0]);

    double *tmp = (double*)malloc(sizeof(buffer->array[0]) * new_capacity);
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
ssize_t popArraydouble(ArrayBufferdouble *buffer, unsigned int pos) {

    if(buffer == NULL || buffer->array == NULL || pos < 0) return -1;

    memmove(buffer->array + pos, buffer->array + pos + 1, (buffer->length - pos - 1) * sizeof(buffer->array[0]));

    buffer->length--;

    return 1;

};

double removeArraydouble(ArrayBufferdouble *buffer, double value) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    unsigned int pos = 0;
    double to_be_removed = 0;

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
ssize_t reverseArraydouble(ArrayBufferdouble *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    double *tmp = (double*)malloc(sizeof(buffer->array[0]) * buffer->capacity);
    if(tmp == NULL) return -1;

    for(int i = 0; i < buffer->length; i++) {
        tmp[i] = buffer->array[buffer->length - i - 1];
    };

    free(buffer->array);
    buffer->array = tmp;

    return 1;

};

int qsortCompdouble(const void *a, const void *b) {
    return *(double*)a - *(double*)b;
};

ssize_t sortArraydouble(ArrayBufferdouble *buffer) {

    if(buffer == NULL || buffer->array == NULL) return -1;

    qsort(buffer->array, buffer->length, sizeof(buffer->array[0]), qsortCompdouble);

    return 1;
};