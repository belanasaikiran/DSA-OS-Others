#include<stdio.h>
#include <stdint.h>

typedef struct{
    int* lenght;
    int* items;
    int* capacity;
} intArray;

typedef struct{
    char* chars;
    int32_t length;
} String;

typedef struct User{
    String name;
    // User* friend;
    int32_t friendIndex;
} relationship;
