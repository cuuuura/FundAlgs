#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "vector.h"

void flag_h(const long x) {
    size_t count = 0;
    for (size_t i = 1; i <= 100; ++i) {
        if (!(i % x)) {
            printf("%ld\n", i);
            count++;
        }
    }

    if (!count) {
        printf("No such numbers\n");
    }
}

void flag_p(const long x){
    int sqrt_x = sqrt(x);
    bool prime = true;
    for (int i = 2; i <= sqrt_x; ++i){ 
        if (!(x % i)) {
            prime = false;
            break;
        }
    }

    if (prime) printf("Prime number\n");
    else printf("Composite number\n");
}

void flag_s(const long x) {
    char NS16[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    if (x == 0) {
        printf("0");
    }
    else {
        Vector * vector = vector_create();
        long temp_x = x;
        while (temp_x != 0){
            vector_push(vector, NS16[temp_x % 16]);
            temp_x /= 16;
        }

        while (vector_get(vector, vector->size - 1) == '0') {
            vector_pop(vector);
        }
        
        for (int i = vector->size - 1; i >= 0; i--) {
            printf("%c ", vector_get(vector, i));
        }
        
        vector_free(vector);
    }  
    printf("\n");
}

void flag_e(long x) {
    if (!((x >= 1) && (x <= 10))) {
        fprintf(stderr, "Number should be from 1 .. 10");
        return;
    }

    printf("Основание\tСтепень\t\tРезультат\n");

    long res;
    for (long base = 1; base <= 10; base++) {
        res = pow(base, x);
        printf("%ld\t\t%ld\t\t%ld\n", base, x, res);
    }
}

void flag_a(long x) {
    long res = (1 + x) * x / 2;
    printf("Sum 1 .. %ld = %ld\n", x, res);
}

void flag_f(long x) {
    long res = 1;
    for (long i = 2; i <= x; i++) {
        res *= i;
    }
    printf("%ld! = %ld\n", x, res);
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <x> <flag>\n", argv[0]);
        return 1;
    }

    char * str_x = argv[1];
    char * flag = argv[2];

    long x = strtol(str_x, NULL, 10);

    if (strcmp(flag, "-h") == 0) flag_h(x);
    else if (strcmp(flag, "-p") == 0) flag_p(x);
    else if (strcmp(flag, "-s") == 0) flag_s(x);
    else if (strcmp(flag, "-e") == 0) flag_e(x);
    else if (strcmp(flag, "-a") == 0) flag_a(x);
    else if (strcmp(flag, "-f") == 0) flag_f(x);
    else {
        printf("Warning: unknown flag");
        return 2;
    }

    return 0;

}