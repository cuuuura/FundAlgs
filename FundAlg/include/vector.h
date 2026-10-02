#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * data;
    size_t size;
    size_t capacity;
} Vector;

Vector * vector_create();

int vector_push(Vector * vector, char c);
void vector_pop(Vector * vector);
char vector_get(Vector * vector, size_t ind);

void vector_free(Vector * vector);

