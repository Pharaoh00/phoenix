#include "./arraybuffer.h"

ArrayBuffer *initializeArrayBuffer(unsigned int capacity, int type) {

    if(capacity == 0) return NULL;

    ArrayBuffer *tmp = (ArrayBuffer*)malloc(sizeof(ArrayBuffer));
    if(tmp == NULL) return NULL;

    unsigned int new_capacity = capacity + 1;

    tmp->data = (ArrayBufferType*)malloc(new_capacity * sizeof(ArrayBufferType));
    if(tmp->data == NULL) {
        free(tmp);
        return NULL;
    };

    memset(&(tmp->data[capacity]), 0, sizeof(ArrayBufferType));
    tmp->capacity = new_capacity;
    tmp->type = type;
    tmp->length = 0;

    return tmp;

};