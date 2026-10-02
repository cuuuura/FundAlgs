#include "vector.h"

Vector * vector_create() {
    Vector * vector = (Vector *)malloc(sizeof(Vector));

    vector->size = 0;
    vector->capacity = 10*sizeof(char);
    vector->data = (char *)malloc(vector->capacity*sizeof(char));

    return vector;
}

int vector_push(Vector * vector, char c) {
    if (vector->size >= vector->capacity) {
        size_t new_capacity = 2*vector->capacity;
        char * new_data = realloc(vector->data, new_capacity*sizeof(char));

        if (!new_data) return 3;
        
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    vector->data[vector->size] = c;
    vector->size++;

    return 0;
}

char vector_get(Vector * vector, size_t ind) {
    if (ind < vector->size) {
        return vector->data[ind];
    }
    return 0;
}

void vector_pop(Vector * vector){
    if (vector->size > 0) {
        vector->size--;
    }
}

void vector_free(Vector * vector) {
    free(vector->data);
    free(vector);
}