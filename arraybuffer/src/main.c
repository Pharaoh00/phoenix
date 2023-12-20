#include "./arraybufferint.h"

int main() {

    ArrayBufferInt *my_array = initializeArrayBufferInt(1);
    appendArrayInt(my_array, 1);
    appendArrayInt(my_array, 2);
    appendArrayInt(my_array, 3);
    appendArrayInt(my_array, 4);
    appendArrayInt(my_array, 5);
    appendArrayInt(my_array, 6);
    appendArrayInt(my_array, 7);
    appendArrayInt(my_array, 8);

    printf("Array: [");
    for(int i = 0; i < my_array->length; i++) {
        printf(" %d", my_array->array[i]);
    };
    printf(" ]\n");

    insertArrayInt(my_array, 11, 3);
    printf("Array: [");
    for(int i = 0; i < my_array->length; i++) {
        printf(" %d", my_array->array[i]);
    };
    printf(" ]\n");

    popArrayInt(my_array, 3);
    printf("Array: [");
    for(int i = 0; i < my_array->length; i++) {
        printf(" %d", my_array->array[i]);
    };
    printf(" ]\n");

    reverseArrayInt(my_array);
    printf("Array: [");
    for(int i = 0; i < my_array->length; i++) {
        printf(" %d", my_array->array[i]);
    };
    printf(" ]\n");

    ArrayBufferInt *my_array2 = initializeArrayBufferInt(1);
    appendArrayInt(my_array2, 9);
    appendArrayInt(my_array2, 8);
    appendArrayInt(my_array2, 7);
    appendArrayInt(my_array2, 6);
    appendArrayInt(my_array2, 5);
    appendArrayInt(my_array2, 4);
    appendArrayInt(my_array2, 3);
    appendArrayInt(my_array2, 2);
    appendArrayInt(my_array2, 1);

    printf("Array: [");
    for(int i = 0; i < my_array2->length; i++) {
        printf(" %d", my_array2->array[i]);
    };
    printf(" ]\n");

    sortArrayInt(my_array2);

    printf("Array: [");
    for(int i = 0; i < my_array2->length; i++) {
        printf(" %d", my_array2->array[i]);
    };
    printf(" ]\n");

    return 0;
};